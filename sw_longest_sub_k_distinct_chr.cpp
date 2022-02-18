#include <iostream>
#include <string>
#include <unordered_map>

using namespace std; 

int findLength(string str, int k) {
   int windowStart = 0, maxLength = 0; 
   unordered_map<char, int> charFrequencyMap; 

   for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
       charFrequencyMap[str[windowEnd]]++; 

       while (charFrequencyMap.size() > k) {
         charFrequencyMap[str[windowStart]]--; 
         if (charFrequencyMap[str[windowStart]] == 0) {
             charFrequencyMap.erase(str[windowStart]); 
         }
         windowStart++; 
       }

       maxLength = max(maxLength, windowEnd - windowStart + 1); 
   } 
   return maxLength; 
}

int main() {
    cout << findLength("cbbebi", 3); 
}