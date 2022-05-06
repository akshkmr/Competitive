#include <iostream>
#include <vector>

using namespace std; 



    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res; 
        
        int i; 
        for (i=0; i < intervals.size() && intervals[i][1] < newInterval[0]; i++) {
            res.push_back(intervals[i]); 
        }
        
        int j; 
        for (j=i; j < intervals.size() && intervals[j][0] <= newInterval[1]; j++) {
               newInterval[0] = min(intervals[j][0], newInterval[0]);
               newInterval[1] = max(intervals[j][1], newInterval[1]);  
        }
        
        res.push_back(newInterval); 
        
        cout << j << endl; 
        
        while (j < intervals.size()) {
            res.push_back(intervals[i]); 
            j++; 
        }

        return res; 
    }

int main() {
    vector<vector<int>> input = {{1, 2}, {3, 5}, {7, 9}, {10, 11}}; 
    vector<int> interval = {4, 8};

    vector<vector<int>> res = insert(input, interval);

    for (auto vec : res) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl; 
    }
}