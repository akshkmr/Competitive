#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<vector<int>> triplets; 

void searchPair(vector<int> arr, int targetSum, int left) {
    int right = arr.size() - 1; 
    while (left < right)
    {
        int currentSum = arr[left] + arr[right]; 

        if (currentSum == targetSum) {
            triplets.push_back({-targetSum, arr[left], arr[right]}); 
            left++; 
            right--; 

            while (left < right && arr[left] == arr[left-1]) {
                left++; 
            }
            while (left < right && arr[right] == arr[right+1]) {
                right--; 
            }
        } else if (targetSum > currentSum) {
            left++;
        } else {
            right--; 
        }
    }
    
}

void searchTriplets(vector<int> arr) {
   sort(arr.begin(), arr.end()); 
   for (int i=0; i<arr.size()-2; i++) {
       if (i > 0 && arr[i] == arr[i-1])
            continue; 
        searchPair(arr, -arr[i], i+1); 
   }
}

int main() {
    searchTriplets(vector<int>{-3, 0, 1, 2, -1, 1, -2}); 

    for (auto vec : triplets) {
        cout << "["; 
        for (auto num : vec) {
            cout << num << " "; 
        }
        cout << "]"; 
    }
    cout << endl; 
}