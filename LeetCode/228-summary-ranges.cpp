#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>

using namespace std; 


// https://leetcode.com/problems/summary-ranges/

string range(int start, int stop) {
    if (start == stop) {
        return to_string(start); 
    } else {
        return to_string(start) + string("->") + to_string(stop); 
    }
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res; 
    switch (nums.size()) {
        case 0: return {}; 
        case 1: return {to_string(nums[0])}; 
    }
    int rangeStart = nums[0]; 
    for (int i = 1; i<nums.size(); i++) {
        if (nums[i] != nums[i-1] + 1) {
            // we just found a break, for example [5, 7]
            res.push_back(range(rangeStart, nums[i-1])); 
            rangeStart = nums[i]; 
        } else if (i == nums.size() - 1) {
            res.push_back(range(rangeStart, nums[i])); 
            return res; 
        }
    }
    
    res.push_back(to_string(nums[nums.size() - 1])); 
    return res; 
}

int main() {

}