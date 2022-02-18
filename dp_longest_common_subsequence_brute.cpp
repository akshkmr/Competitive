#include <iostream>
#include <vector>

using namespace std; 

int findLCSLengthRecursive(string s1, string s2, int i1, int i2) {
    // base case
    if (i1 == s1.length() || i2 == s2.length())
        return 0; 
    
    int count=0;
    if (s1[i1] == s2[i2]) {
        count = 1 + findLCSLengthRecursive(s1, s2, i1+1, i2+1); 
    } 
    int c1 = findLCSLengthRecursive(s1, s2, i1+1, i2); 
    int c2 = findLCSLengthRecursive(s1, s2, i1, i2+1); 
    
    return max(count, max(c1,c2)); 
}

int findLCSLength(string s1, string s2) {
    return findLCSLengthRecursive(s1, s2, 0, 0);
}

int main() {
    cout << findLCSLength("passport", "ppsspt") << endl; 
}