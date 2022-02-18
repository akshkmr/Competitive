#include <iostream>
#include <string>
#include <unordered_map>

using namespace std; 

int findLength(string str) {
    int windowStart = 0, maxLength = 0; 
    unordered_map<char,int> charIndexMap; 
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
        
        if (charIndexMap.find(str[windowEnd]) != charIndexMap.end()) {
            windowStart = max(windowStart, charIndexMap[str[windowEnd]]+1); 
        }

        charIndexMap[str[windowEnd]] = windowEnd; 
        maxLength = max(maxLength, windowEnd - windowStart + 1); 
    }
    return maxLength; 
}

int main() {
    cout << findLength("aabccbb") << endl; 
}