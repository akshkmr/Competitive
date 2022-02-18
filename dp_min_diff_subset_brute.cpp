#include <iostream>
#include <vector>

using namespace std; 

int canPartitionRecursive(vector<int> nums, int currentIndex, int sum1, int sum2) {
    if (currentIndex == nums.size()) {
        return abs(sum1-sum2); 
    }

    int diff1 = canPartitionRecursive(nums, currentIndex+1, sum1+nums[currentIndex], sum2);

    int diff2 = canPartitionRecursive(nums, currentIndex+1, sum1, sum2+nums[currentIndex]);

    return min(diff1, diff2); 
}

int canPartition(vector<int> nums) {
    return canPartitionRecursive(nums, 0, 0, 0); 
}

int main() {
    cout << canPartition(vector<int>{1,2,3,4}); 
}