#include <iostream>
#include <vector>

using namespace std; 


double findMedianSortedArrays(const vector<int> nums1, const vector<int> nums2) {
    int n1 = nums1.size(); 
    int n2 = nums2.size(); 
    
    int lo = 0, hi = n1; 
    
    int l1, l2, r1, r2; 
    
    while (lo <= hi) {
        cout << lo << " " << hi << endl; 

        int cut1 = (lo + hi) / 2;
        int cut2 = (n1+n2)/2 - cut1; 
        
        l1 = (cut1 == 0) ? numeric_limits<int>::min() : nums1[cut1-1]; 
        l2 = (cut2 == 0) ? numeric_limits<int>::min() : nums2[cut2-1]; 
        r1 = (cut1 == n1) ? numeric_limits<int>::max() : nums1[cut1]; 
        r2 = (cut2 == n2) ? numeric_limits<int>::max() : nums2[cut2]; 
        cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl; 
        
        if (l1 <= r2 && l2 <= r1) {
            return (n1+n2)%2 == 0 ? ((max(l1, l2) + min(r1, r2)) / 2.0) : min(r1, r2); 
        }

        
        
        if (l1 > r2) {
            hi = cut1 - 1; 
        } else if (l2 > r1) {
            lo = cut1 + 1; 
        } 

        cout << lo << " " << hi << endl; 

    }
    
    return -1.0; 
}

int main() {
    vector<int> nums1 = {2,3,4,5}; 
    vector<int> nums2 = {1}; 

    findMedianSortedArrays(nums1, nums2);
}