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
Node* reverse(Node* head) {
    Node* current = head; 
    Node* prev = nullptr;
    Node* next = nullptr; 

    while(current != nullptr) {
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    }

    return prev; 
}

int main() {
    Node *head = new Node(2); 
    head->next = new Node(4); 
    head->next->next = new Node(6); 
    head->next->next->next = new Node(8); 
    head->next->next->next->next = new Node(10); 

    Node* result = reverse(head); 

    while (result != nullptr) {
        cout << result->value << endl; 
        result = result->next; 
    }
}