#include <iostream>
#include <vector> 
#include <limits>

using namespace std; 

int countChangeRecursive(vector<vector<int>> &dp, vector<int> &denominations, int total, int currentIndex) {
    if (total == 0) {
        return 0; 
    }

    if (total <= 0 || currentIndex >= denominations.size()) {
        return numeric_limits<int>::max(); 
    }

    if (!dp[currentIndex][total]) {
        int count1 = numeric_limits<int>::max(); 
        if (denominations[currentIndex] <= total) {
            int res = countChangeRecursive(dp, denominations, total-denominations[currentIndex], currentIndex); 
            if (res != numeric_limits<int>::max()) {
                count1 = res + 1; 
            }
        }

        int count2 = countChangeRecursive(dp, denominations, total, currentIndex+1);

        dp[currentIndex][total] = min(count1, count2);
    }

    return dp[currentIndex][total]; 
}

int countChange(vector<int> &denominations, int total) {
    vector<vector<int>> dp(denominations.size(), vector<int>(total+1)); 
    int result = countChangeRecursive(dp, denominations, total, 0);
    return (result == numeric_limits<int>::max() ? -1 : result); 
}

int main() {
    vector<int> denominations = {1,2,3};
    cout << countChange(denominations, 5) << endl; 
}
