#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int findLCSLengthRecursive(string &s1, string &s2, int i1, int i2, int count) {
    if (i1 == s1.length() || i2 == s2.length()) 
        return count; 

    if (s1[i1] == s2[i2]) {
        count = findLCSLengthRecursive(s1, s2, i1+1, i2+1, count+1);
    }

    int c1 = findLCSLengthRecursive(s1, s2, i1+1, i2, 0);
    int c2 = findLCSLengthRecursive(s1, s2, i1, i2+1, 0); 

    // As max can be find for two numbers only
    return max(count, max(c1, c2)); 
}

int findLCSLength(string &s1, string &s2) {
   return findLCSLengthRecursive(s1, s2, 0, 0, 0); 
}

int main() {
    string s1 = "abdca"; 
    string s2 = "cbda"; 
    cout << findLCSLength(s1, s2) << endl; 
}