#include <iostream>
#include <vector>

using namespace std; 

void searchPair(vector<int> nums, int targetSum, int left, vector<vector<int>> &triplets) {
    int right = nums.size() - 1;

    while (left < right) {
        int currentSum = nums[left] + nums[right]; 

        if (currentSum == targetSum) {
            triplets.push_back({-targetSum, nums[left], nums[right]});
            left++; 
            right--; 
            while (left < right && nums[left] == nums[left-1]) {
                left++; 
            }

            while (left < right && nums[right] == nums[right+1]) {
                right++; 
            }
        } else if (targetSum > currentSum) {
            left++; 
        } else {
            right--; 
        }
    }
}

vector<vector<int>> searchTriplets(vector<int> nums) {
    sort(nums.begin(), nums.end()); 
    vector<vector<int>> triplets; 

    for (int i=0; i<nums.size()-2; i++) {
        if (i > 0 && nums[i] == nums[i-1])
            continue; 
        searchPair(nums, -nums[i], i+1, triplets); 
    }

    return triplets; 
}

int main() {
    vector<int> vec = {-3, 0, 1, 2, -1, 1, -2}; 

    auto result = searchTriplets(vec); 

    for (auto triplet : result) {
        for (auto num : triplet) {
            cout << num << " "; 
        }
        cout << endl; 
    }
}