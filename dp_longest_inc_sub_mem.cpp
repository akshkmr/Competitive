#include <iostream>
#include <vector>

using namespace std; 

int findLISLengthRecursive(vector<vector<int>> dp, vector<int> nums, int currentIndex, int prevIndex) {
    if (currentIndex == nums.size()) 
        return 0; 

    if (dp[currentIndex][prevIndex+1] == -1) {
        int c1=0; 
        if (prevIndex == -1 || nums[currentIndex] > nums[prevIndex]) {
            c1 = 1 + findLISLengthRecursive(dp, nums, currentIndex+1, currentIndex); 
        }

        int c2 = findLISLengthRecursive(dp, nums, currentIndex + 1, prevIndex); 
        dp[currentIndex][prevIndex+1] = max(c1, c2);
    }

    return dp[currentIndex][prevIndex+1]; 
}
 
int findLISLength(vector<int> nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1)); 
    return findLISLengthRecursive(dp, nums, 0, -1); 
}

int main() {
    vector<int> nums = {4,2,3,6,10,1,12}; 
    cout << findLISLength(nums) << endl; 
}