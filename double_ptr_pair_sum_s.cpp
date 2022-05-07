#include <iostream>
#include <vector>

using namespace std; 

pair<int, int> pairWithTargetSum(vector<int> arr, int sum) {
   sort(arr.begin(), arr.end()); 
   int start = 0, end = arr.size() - 1; 

   while (start < end) {
       int currentSum = arr[start] + arr[end]; 
       if (currentSum == sum) return make_pair(arr[start], arr[end]); 
       else if (currentSum < sum) {
           start++;
       } else {
           end--; 
       }
   }

   return make_pair(-1, -1); 
}

int main() {
    auto result = pairWithTargetSum(vector<int>{1, 2, 3, 4, 6}, 6); 
    cout << result.first << ", " << result.second << ", " << endl; 
}