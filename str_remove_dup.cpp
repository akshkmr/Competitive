#include <iostream>
#include <string>
#include <unordered_map>

using namespace std; 

int main() {
    string str = "geeksforgeeks"; 
    string result = ""; 

    unordered_map<char, int> freequencyMap; 

    for (int i=0; i < str.length(); i++) {
       freequencyMap[str[i]]++;  
       if (freequencyMap[str[i]] == 1) {
           result+=str[i]; 
       } 
    }

    cout << result; 
}