#include <iostream>
#include <vector>
#include <limits>

using namespace std; 

int findMinSubArray(int S, vector<int> arr) {
   int windowStart = 0, minLength = numeric_limits<int>::max(), windowSum = 0; 
   for (int windowEnd=0; windowEnd < arr.size(); windowEnd++) {
       windowSum+=arr[windowEnd]; 

       while (windowSum >= S) {
        minLength = min(minLength, (windowEnd - windowStart + 1)); 
        windowSum-=arr[windowStart]; 
        windowStart++; 
       }
   }

   return minLength == numeric_limits<int>::max() ? 0 : minLength; 
}

int main() {
    int result = findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2}); 
    cout << result << endl; 
}