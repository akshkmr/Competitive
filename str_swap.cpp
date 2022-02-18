#include <iostream>
#include <string>

using namespace std; 

void swap(string *s1, string *s2) {
    string *temp = s1; 
    s1 = s2; 
    s2 = temp; 
}

int main() {
    string s1 = "I love"; 
    string s2 = "Bobby"; 

    swap(s1,s2); 

    cout << s1 << " " << s2 << endl; 
}