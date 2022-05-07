#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int findLCSLengthRecursive(vector<vector<vector<int>>> dp, string &s1, string &s2, int i1, int i2, int count) {
    if (i1 == s1.length() || i2 == s2.length()) 
        return count; 

    if (dp[i1][i2][count] == -1) {
        
        if (s1[i1] == s2[i2]) {
            count = findLCSLengthRecursive(dp, s1, s2, i1+1, i2+1, count+1);
        }

        int c1 = findLCSLengthRecursive(dp, s1, s2, i1+1, i2, 0);
        int c2 = findLCSLengthRecursive(dp, s1, s2, i1, i2+1, 0); 

        dp[i1][i2][count] = max(count, max(c1, c2)); 
    }

    return dp[i1][i2][count]; 
}

int findLCSLength(string &s1, string &s2) {
   int macLength = max(s1.length(), s2.length()); 
   vector<vector<vector<int>>> dp(s1.length(), vector<vector<int>>(s2.length(), vector<int>(macLength, -1))); 
   return findLCSLengthRecursive(dp, s1, s2, 0, 0, 0); 
}

int main() {
    string s1 = "passport"; 
    string s2 = "ppsspt"; 
    cout << findLCSLength(s1, s2) << endl; 
}