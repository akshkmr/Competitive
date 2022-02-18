#include <iostream>
#include <vector>

using namespace std; 

bool canPartitionRecursive(vector<int> &nums, int sum, int currentIndex) {

    if (sum == 0)
        return true; 

    if (currentIndex >= nums.size())
        return false; 

    if (nums[currentIndex] <= sum) {
        if (canPartitionRecursive(nums, sum - nums[currentIndex], currentIndex + 1)) {
            return true; 
        }
    }        

    return canPartitionRecursive(nums, sum, currentIndex+1); 
}

bool canPartition(vector<int> &nums) {
    int sum = 0; 
    for (auto num : nums) {
        sum+=num; 
    }

    if (sum % 2 != 0) 
        return false; 

    return canPartitionRecursive(nums, sum/2, 0);     
}

int main() {
    vector<int> nums = {2,3,4,6};
    cout << canPartition(nums) << endl; 
}