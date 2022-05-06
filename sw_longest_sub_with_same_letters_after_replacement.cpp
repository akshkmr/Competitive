#include <iostream>
#include <string>
#include <unordered_map>

using namespace std; 

int findLength(string str, int k) {
    int start = 0, maxLen = 0, maxRepeatLetterCount = 0; 
    unordered_map<char, int> charFrequencyMap; 

    for (int end = 0; end < str.length(); end++) {
        charFrequencyMap[str[end]]++; 
        maxRepeatLetterCount = max(maxRepeatLetterCount, charFrequencyMap[str[end]]); 

        if (end - start + 1 - maxRepeatLetterCount > k) {
            charFrequencyMap[str[start]]--; 
            start++; 
        }

        maxLen = max(maxLen, end - start + 1); 
    }

    return maxLen; 
}

int main() {
    cout << findLength("aabccbb", 2) << endl; 
}