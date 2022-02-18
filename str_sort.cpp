#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> name = {"john", "bobby", "dear", "guy", "jacob"}; 

    sort(name.begin(), name.end()); 

    for (auto num : name) {
        cout << num << endl; 
    }
}