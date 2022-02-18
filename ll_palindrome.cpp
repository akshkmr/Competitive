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

bool isPalindrome(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return true; 
    }

    Node *fast = head; 
    Node *slow = head; 

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next; 
        slow = slow->next; 
    }

    Node *headSecondHalf = reverse(slow); 

    // Need to do this question (use stack)
}

int main() {
    Node *head = new Node(2); 
    head->next = new Node(4); 
    head->next->next = new Node(6); 
    head->next->next->next = new Node(4); 
    head->next->next->next->next = new Node(2); 

    cout << isPalindrome(head) << endl; 
}