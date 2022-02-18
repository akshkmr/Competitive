#include <iostream>

using namespace std; 

class Node {
    public:
        int value = 0;
        Node *next; 

        Node(int value) {
            this->value = value; 
            this->next = nullptr; 
        }
};

int findMiddle(Node* head) {
    Node *fast = head; 
    Node *slow = head; 

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next; 
        slow = slow->next; 
    }

    return slow->value; 
}

int main() {
    Node *head = new Node(1); 
    head->next = new Node(2); 
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4); 
    head->next->next->next->next = new Node(5); 

    cout << findMiddle(head) << endl; 
}