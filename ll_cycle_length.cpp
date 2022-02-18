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

int calculeLength(Node *slow) {
    Node *current = slow;
    int length = 0; 

    do {
        current = current->next; 
        length++; 
    } while (current != slow);

    return length;  
}   

int findCycleLength(Node *head) {
    Node *slow = head; 
    Node *fast = head; 

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next; 
        fast = fast->next->next; 

        if (slow == fast) {
            return calculeLength(slow); 
        }
    }

    return 0; 
    
}


int main() {
    Node *head = new Node(1); 
    head->next = new Node(2); 
    head->next->next = new Node(3); 
    head->next->next->next = new Node(4); 
    head->next->next->next->next = new Node(5); 
    head->next->next->next->next->next = new Node(6); 
    head->next->next->next->next->next->next = head->next->next; 

    cout << findCycleLength(head) << endl;
}