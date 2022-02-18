#include <iostream>
#include <vector>

using namespace std; 

int findLISLengthRecursive(vector<int> nums, int currentIndex, int prevIndex) {
    if (currentIndex == nums.size()) 
        return 0; 

    int c1=0; 
    if (prevIndex == -1 || nums[currentIndex] > nums[prevIndex]) {
        c1 = 1 + findLISLengthRecursive(nums, currentIndex+1, currentIndex); 
    }

    int c2 = findLISLengthRecursive(nums, currentIndex + 1, prevIndex); 

    return max(c1, c2); 
}
 
int findLISLength(vector<int> nums) {
    return findLISLengthRecursive(nums, 0, -1); 
}

int main() {
    vector<int> nums = {4,2,3,6,10,1,12}; 
    cout << findLISLength(nums) << endl; 
}