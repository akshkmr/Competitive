#include <iostream>
#include <vector>

using namespace std; 

pair<int, int> pairWithTargetSum(vector<int> arr, int sum) {
   int left = 0, right = arr.size() - 1; 

   while (left < right) {
        int currentSum = arr[left] + arr[right]; 
        if (currentSum == sum)
            return {left, right}; 
        else if (currentSum < sum) 
            left++; 
        else 
            right--; 
   }

   return {-1,-1}; 
}

int main() {
    auto result = pairWithTargetSum(vector<int>{1, 2, 3, 4, 6}, 6); 
    cout << result.first << ", " << result.second << ", " << endl; 
}