#include <iostream>

using namespace std; 

class Node {
    public:
        int value = 0; 
        Node *next; 

        Node(int value) {
            this->value = value; 
            next = nullptr; 
        }
}; 

bool hasCycle(Node *head) {
    Node *slow = head; 
    Node *fast = head; 

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next; 
        fast = fast->next->next; 

        if (slow == fast) {
            return true; 
        }
    }

    return false; 
    
}

int main() {
    Node *head = new Node(1); 
    head->next = new Node(2); 
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4); 
    head->next->next->next->next = new Node(5); 
    head->next->next->next->next->next = new Node(6); 

    cout << hasCycle(head) << endl; 

    head->next->next->next->next->next->next = head->next->next; 
    cout << hasCycle(head) << endl;
}