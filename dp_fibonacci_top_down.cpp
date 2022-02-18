#include <iostream> 
#include <vector>

using namespace std; 

int calculateFibonacciRecursive(vector<int> &memorize, int n) {
    if (n<2) {
        return n; 
    }

    if (memorize[n] != 0) {
        return memorize[n]; 
    }

    memorize[n] = calculateFibonacciRecursive(memorize, n-1) + calculateFibonacciRecursive(memorize, n-2);
    return memorize[n]; 
}

int calculateFibonacci(int n) {
    vector<int> memorize(n+1,0);
    return calculateFibonacciRecursive(memorize, n); 
} 

int main() {
    cout << calculateFibonacci(6) << endl; 
}