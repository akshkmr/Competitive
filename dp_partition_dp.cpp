#include <iostream>
#include <vector>

using namespace std; 

bool canPartitionRecursive(vector<vector<int>> &dp, vector<int> &nums, int sum, int currentIndex) {

    if (sum == 0)
        return true; 

    if (currentIndex >= nums.size())
        return false; 

    if (dp[currentIndex][sum] == -1) {
        if (nums[currentIndex] <= sum) {
            if (canPartitionRecursive(dp, nums, sum - nums[currentIndex], currentIndex + 1)) {
                dp[currentIndex][sum] = 1; 
                return true; 
            }
    }        

    dp[currentIndex][sum] = canPartitionRecursive(dp, nums, sum, currentIndex+1); 
    
    }

    return dp[currentIndex][sum] == 1 ? true : false; 
}

bool canPartition(vector<int> &nums) {
    int sum = 0; 
    for (auto num : nums) {
        sum+=num; 
    }

    if (sum % 2 != 0) 
        return false; 

    vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, -1));

    return canPartitionRecursive(dp, nums, sum/2, 0);     
}

int main() {
    vector<int> nums = {1,2,3,4};
    cout << canPartition(nums) << endl; 
}