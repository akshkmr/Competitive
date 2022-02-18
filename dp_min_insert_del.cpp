#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int findLCSLengthRecursive(vector<vector<int>> dp, string &s1, string &s2, int i1, int i2) {
    if (i1 == s1.length() || i2 == s2.length())
        return 0; 

    if (!dp[i1][i2]) {
        int count = 0; 
        if (s1[i1] == s2[i2]) {
            count = 1 + findLCSLengthRecursive(dp, s1, s2, i1+1, i2+1);
        } 
        int c1 = findLCSLengthRecursive(dp, s1, s2, i1, i2+1); 
        int c2 = findLCSLengthRecursive(dp, s1, s2, i1+1, i2); 
        dp[i1][i2] = max(count, max(c1, c2)); 
    }    

    return dp[i1][i2]; 
}

int findLCSLength(string &s1, string &s2) {
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length())); 
    return findLCSLengthRecursive(dp, s1, s2, 0, 0); 
}

void findMDI(string &s1, string &s2) {
    int lcs = findLCSLength(s1, s2);
    cout << "Minimum deletion needed: " << (s1.length() - lcs) << endl; 
    cout << "Minimum insertion needed: " << (s2.length() - lcs) << endl;
}

int main() {
   string s1 = "passport"; 
   string s2 = "ppsspt";  
   findMDI(s1, s2);  
}