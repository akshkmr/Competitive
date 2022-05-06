#include <iostream>
#include <vector>
#include <limits>

using namespace std; 

int findMinSubArray(int S, vector<int> arr) {
   int start = 0, windowSum = 0, minLength = INT_MAX; 

   for (int end = 0; end < arr.size(); end++) {
       windowSum += arr[end]; 

       while (windowSum >= S) {
           minLength = min(minLength, end - start + 1); 
           windowSum -= arr[start]; 
           start++;  
       }
   }

   return minLength == INT_MAX ? 0 : minLength; 
}

int main() {
    int result = findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2}); 
    cout << result << endl; 
}