#include <iostream>
#include <vector>

using namespace std; 

int canPartitionRecursive(vector<vector<int>> &dp, vector<int> nums, int currentIndex, int sum1, int sum2) {
    if (currentIndex == nums.size()) {
        return abs(sum1-sum2); 
    }

    if (!dp[currentIndex][sum1]) {
        int diff1 = canPartitionRecursive(dp, nums, currentIndex+1, sum1+nums[currentIndex], sum2);

        int diff2 = canPartitionRecursive(dp, nums, currentIndex+1, sum1, sum2+nums[currentIndex]); 

        dp[currentIndex][sum1] = min(diff1, diff2);
    }

    return dp[currentIndex][sum1]; 
}

int canPartition(vector<int> nums) {
    int sum = 0; 
    for (int i=0; i<nums.size(); i++) 
        sum+=nums[i];
     
    vector<vector<int>> dp(nums.size(), vector<int>(sum+1));
    return canPartitionRecursive(dp, nums, 0, 0, 0); 
}

int main() {
    cout << canPartition(vector<int>{1,2,3,9}); 
}