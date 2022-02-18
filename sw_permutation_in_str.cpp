#include <iostream>
#include <string>
#include <unordered_map>

using namespace std; 

bool findPermutation(string str, string pattern) {
    int windowStart = 0, matched = 0; 
    
    unordered_map<char, int> charFrequencyMap; 
    for (char chr : pattern) {
        charFrequencyMap[chr]++; 
    }

    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
        char rightChar = str[windowEnd]; 

        if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
            charFrequencyMap[rightChar]--; 
            if (charFrequencyMap[rightChar] == 0) {
                matched++; 
            }
        }

        if (charFrequencyMap.size() == matched) {
            return true; 
        }

        if ((windowEnd-windowStart+1) >= pattern.length()) {
            char leftChar = str[windowStart]; 
            windowStart++; 
            if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
                if (charFrequencyMap[leftChar] == 0) {
                    matched--;
                }
                charFrequencyMap[leftChar]++;
            }
        }
    }

    return false; 
}

int main() {
    cout << findPermutation("aaacb", "abc") << endl; 
}