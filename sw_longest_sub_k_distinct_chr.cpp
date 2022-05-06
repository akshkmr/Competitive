#include <iostream>
#include <string>
#include <unordered_map>

using namespace std; 

int findLength(string str, int k) {
   int start = 0, maxLength = 0; 
   unordered_map<char, int> charFrequencyMap; 

   for (int end = 0; end < str.length(); end++) {
       charFrequencyMap[str[end]]++; 
       
       while (charFrequencyMap.size() > k) {
           
           charFrequencyMap[str[start]]--;  
           if (charFrequencyMap[str[start]] == 0) {
               charFrequencyMap.erase(str[start]); 
           } 

           start++; 
       }

       maxLength = max(maxLength, end - start + 1);  
   }

   return maxLength; 
}

int main() {
    cout << findLength("araaci", 2); 
}