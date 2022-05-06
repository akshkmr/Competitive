#include <iostream>
#include <stack>
#include <vector>
#include <queue>

// https://leetcode.com/problems/basic-calculator/discuss/1457045/C%2B%2B-oror-Explained-oror-Stacks-oror-Beginner-FriendlyEasy-To-Understand


using namespace std; 

int calculate(string s) {
    stack<pair<int, int>> st; 
    
    int sum = 0; 
    int sign = +1; 
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i]; 
        
        if (isdigit(ch)) {
            int num = 0; 
            while (i < s.length() && isdigit(s[i])) {
                num = (num * 10) + (s[i] - '0'); 
                i++; 
            }
            i--; // as for loop also increase i , so if we don't decrease i here a sign will be skipped
            sum += (num * sign); 
            sign = +1; // reseting sign
        }
        
        else if (ch == '(') {
            st.push(make_pair(sum, sign)); 
            
            // Reseting sum and sign for inner bracket calculation
            sum = 0; 
            sign = +1; 
        }
        
        else if (ch == ')') {
            sum = st.top().first + (st.top().second * sum); 
            st.pop(); 
        }
        
        else if (ch == '-') {
            sign = -1 * sign; 
        }
    }
    
    return sum; 
}