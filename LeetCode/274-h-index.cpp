#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std; 

int hIndex(vector<int>& citations) {
    int n = citations.size(); 
    int low = 0, high = n - 1, mid; 
    
    sort(citations.begin(), citations.end()); 
    
    while(low <= high) {
        mid = (low + high) / 2; 
        
        if (citations[mid] == (n-mid)) {
            return citations[mid]; 
        } else if (citations[mid] > (n-mid)) {
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    
    return (n - low); 
}

int main() {
    
}