class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0); 
        ListNode *curr = dummy; 
        
        int carry = 0; 
        
        while (l1 || l2 || carry) {
            int a = l1 ? l1->val : 0, b = l2 ? l2->val : 0; 
            int value = a + b + carry; 
            
            curr->next = new ListNode(value % 10); 
            carry = value / 10; 
            l1 = l1 ? l1->next : nullptr; 
            l2 = l2 ? l2->next : nullptr; 
            curr = curr -> next; 
        }
        
        return dummy->next; 
    }
};