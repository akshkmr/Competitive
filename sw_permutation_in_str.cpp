#include <iostream>
#include <string>
#include <unordered_map>

using namespace std; 

bool findPermutation(string str, string pattern) {
    int start = 0, matched = 0; 
    unordered_map<char, int> charFrequencyMap; 

    for (auto chr : pattern) {
        charFrequencyMap[chr]++;
    }

    for (int end = 0; end < str.length(); end++) {

        if (charFrequencyMap.find(str[end]) != charFrequencyMap.end()) {
            charFrequencyMap[str[end]]--; 
            if (charFrequencyMap[str[end]] == 0) {
                matched++; 
            }
        }

        if (charFrequencyMap.size() == matched) {
            return true; 
        }

        if ((end - start + 1) >= pattern.length()) {
            start++; 
            if (charFrequencyMap.find(str[start]) != charFrequencyMap.end()) {
                if (charFrequencyMap[str[start]] == 0) {
                    matched--; 
                }
                charFrequencyMap[str[start]]++; 
            }
        }
    }

    return false; 
}

int main() {
    cout << findPermutation("aaacb", "abcd") << endl; 
}