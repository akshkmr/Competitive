#include <iostream>
#include <vector>

using namespace std; 

int countRecursive(vector<vector<int>> &dp, vector<int> &num, int sum, int currentIndex) {

    if (sum == 0) {
        return 1; 
    }

    if (sum <= 0 || currentIndex >= num.size()) {
        return 0; 
    }

    if (dp[currentIndex][sum] == -1) {
        int sum1 = 0, sum2 = 0; 

        if (num[currentIndex] <= sum) {
            sum1 = countRecursive(dp, num, sum - num[currentIndex], currentIndex+1); 
        }

        sum2 = countRecursive(dp, num, sum, currentIndex+1); 

        dp[currentIndex][sum] = sum1 + sum2; 
    }

    return dp[currentIndex][sum]; 
}

int count(vector<int> &nums, int sum) {
    vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
    return countRecursive(dp, nums, sum, 0);
}

int main() {
    vector<int> nums = {1, 1, 2, 3}; 

    int maxProfit = count(nums, 4); 
    cout << maxProfit << endl; 
}