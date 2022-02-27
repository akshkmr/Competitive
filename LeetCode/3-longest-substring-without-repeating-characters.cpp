class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart = 0, maxLength = 0; 
        unordered_map<char, int> charIndexMap; 
        
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            
            if (charIndexMap.find(s[windowEnd]) != charIndexMap.end()) {
                windowStart = max(windowStart, charIndexMap[s[windowEnd]]+1); 
            }
            
            charIndexMap[s[windowEnd]] = windowEnd; 
            
            maxLength = max(maxLength, windowEnd - windowStart + 1); 
        }
        
        return maxLength; 
    }
};