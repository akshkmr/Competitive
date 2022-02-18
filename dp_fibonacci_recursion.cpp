#include <iostream> 

using namespace std; 

int calculateFibonacci(int n) {
    if (n < 2) {
        return n; 
    }
    return calculateFibonacci(n-1) + calculateFibonacci(n-2); 
} 

int main() {
    cout << calculateFibonacci(5) << endl; 
}