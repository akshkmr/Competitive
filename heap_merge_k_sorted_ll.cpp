#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

class ListNode {
    public:
        int value = 0; 
        ListNode *next; 

        ListNode(int value) {
            this->value = value; 
            this->next = nullptr; 
        }
}; 

struct compare {
    bool operator()(const ListNode *x, const ListNode *y) {
        return x->value > y->value; 
    }
}; 

ListNode *merge(vector<ListNode *> list) {
    priority_queue<ListNode *, vector<ListNode *>, compare> minHeap; 

    for (auto root : list) {
        if (root != nullptr) {
            minHeap.push(root); 
        }
    }

    ListNode *result = new ListNode(0); 
    ListNode *temp = result; 

    while(!minHeap.empty()) {
        ListNode *curr = minHeap.top(); 
        minHeap.pop(); 

        temp->next = curr;
        temp = temp->next; 

        if (curr->next != nullptr)
            minHeap.push(curr->next);
    }

    return result->next; 
}

void printList(struct ListNode* head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}

// Time Complexity N * logK N is the total number of elements in all the K input arrays

int main() {
    ListNode *l1 = new ListNode(2); 
    l1->next = new ListNode(6); 
    l1->next->next = new ListNode(8); 

    ListNode *l2 = new ListNode(3); 
    l2->next = new ListNode(6); 
    l2->next->next = new ListNode(7); 

    ListNode *l3 = new ListNode(1); 
    l3->next = new ListNode(3); 
    l3->next->next = new ListNode(4);

    ListNode *result = merge(vector<ListNode *>{l1, l2, l3});  

    printList(result); 
}

