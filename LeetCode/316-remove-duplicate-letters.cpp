#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#include <queue>
#include <stack>


using namespace std; 

string removeDuplicateLetters(string s) {
    vector<int> lastIndex(26, 0), visited(26, 0); 
    stack<int> st; 
    
    for (int i = 0; i < s.length(); i++) 
        lastIndex[s[i]-'a'] = i; 
    
    for(int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a'; 
        
        if (visited[c]) continue; 
        
        while (!st.empty() && st.top() > c && i < lastIndex[st.top()]) {
            visited[st.top()] = false; 
            st.pop(); 
        }
        
        st.push(c); 
        visited[c] = true; 
    }
    
    string res = "";
    
    while(!st.empty()) {
        res += (char)(st.top() + 'a'); 
        st.pop(); 
    }
    
    reverse(res.begin(), res.end());
    return res; 
}

int main() {

}