#include <iostream>
#include <vector>
#include <string>

using namespace std; 

vector<string> result; 

void permute(string str, int idx) {
    if (idx == str.length()) {
        result.push_back(str); 
        return; 
    }
    for (int i = idx; i < str.length(); i++) {
        swap(str[i], str[idx]); 
        permute(str, idx+1); 
        swap(str[i], str[idx]); 
    }
    return; 
}

int main() {
    string str = "ABC"; 
    permute(str, 0); 

    for (auto str : result) {
        cout << str << endl; 
    }
}