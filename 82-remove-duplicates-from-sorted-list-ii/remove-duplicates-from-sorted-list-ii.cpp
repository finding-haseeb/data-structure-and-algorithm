class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                int x = curr->val;
                
                while (curr != NULL && curr->val == x) {
                    curr = curr->next;
                }
                
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};