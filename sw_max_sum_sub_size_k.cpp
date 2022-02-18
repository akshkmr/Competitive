#include <iostream>
#include <vector>

using namespace std; 

int findMaxSumSubArray(int k, vector<int> arr) {
    int windowStart = 0, maxSum = 0, windowSum=0; 
    
    for (int windowEnd=0; windowEnd<arr.size(); windowEnd++) {
        windowSum+=arr[windowEnd]; 

        if ((windowEnd-windowStart+1) >= k) {
            maxSum = max(windowSum, maxSum); 
            windowSum-=arr[windowStart]; 
            windowStart++; 
        }
    }

    return maxSum; 
}

int main() {
    cout << findMaxSumSubArray(3, vector<int>{2,1,5,1,3,2}); 
}