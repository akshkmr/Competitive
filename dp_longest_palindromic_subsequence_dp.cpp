#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int findLPSLengthRecursive(string st, vector<vector<int>> dp, int left, int right) {
    if (left > right)
        return 0; 

    // every sequence with one element is a palindrom of length 1
    if (left == right)
        return 1; 

    if (dp[left][right] == -1) {
        // case 1: elements at the beginning and the end are the same
        if (st[left] == st[right]) {
            return 2 + findLPSLengthRecursive(st, dp,left+1, right-1); 
        }

        // case 2: skip one element either from the beginning or the end
        int c1 = findLPSLengthRecursive(st, dp, left+1, right); 
        int c2 = findLPSLengthRecursive(st, dp, left, right-1); 
        dp[left][right] = max(c1, c2); 
    }
    return dp[left][right]; 
}

int findLPSLength(string st) {
    vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1)); 
    return findLPSLengthRecursive(st, dp, 0, st.length()-1); 
}

int main() {
    cout << findLPSLength("cddpd") << endl; 
}
