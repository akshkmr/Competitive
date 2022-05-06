#include <iostream>
#include <string>
#include <unordered_map>

using namespace std; 

int findLength(string str) {
    int start = 0, maxLen = 0; 
    unordered_map<char, int> charIndexMap; 

    for (int end = 0; end < str.length(); end++) {
        
        if (charIndexMap.find(str[end]) != charIndexMap.end()) {
            start = max(start, charIndexMap[str[end]] + 1); 
        }

        maxLen = max(maxLen, (end - start + 1)); 
        charIndexMap[str[end]] = end; 
    }

    return maxLen; 
}

int main() {
    cout << findLength("aabccbb") << endl; 
}