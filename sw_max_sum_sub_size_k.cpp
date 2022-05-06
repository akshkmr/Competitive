#include <iostream>
#include <vector>

using namespace std; 

int findMaxSumSubArray(int k, vector<int> arr) {
    int start = 0, maxSum = 0, windowSum = 0; 

    for (int end = 0; end < arr.size(); end++) {
        windowSum = windowSum + arr[end]; 

        if ((end - start + 1) >= k) {
            maxSum = max(maxSum, windowSum); 
            windowSum -= arr[start]; 
            start++; 
        }
    }

    return maxSum; 
}

int main() {
    cout << findMaxSumSubArray(3, vector<int>{2,1,5,1,3,2}); 
}