#include <iostream>
#include <string>
#include <vector>

using namespace std; 

string longestCommonPrefixUtil(string str1, string str2) {
    string result; 
    int n1 = str1.length(), n2 = str2.length(); 
    
    for (int i = 0, j = 0; i<n1 && j<n2; i++, j++) {
        if (str1[i] != str2[j])
            break; 
        result+=str1[i]; 
    }
    
    return result; 
}

string longestCommonPrefixRecursive(vector<string> strs, int low, int high) {
    string result; 
    if (low == high) 
        return strs[low]; 
    
    if (low < high) {
        int mid = (low + high) / 2; 
        
        string str1 = longestCommonPrefixRecursive(strs, low, mid); 
        string str2 = longestCommonPrefixRecursive(strs, mid+1, high); 
        
        result = longestCommonPrefixUtil(str1, str2); 
    }
    
    return result; 
}

string longestCommonPrefix(vector<string>& strs) {
    return longestCommonPrefixRecursive(strs, 0, strs.size()-1); 
}

int main() {
    vector<string> strs = {"flower", "flight", "flow"}; 
    cout << longestCommonPrefix(strs) << endl;
}