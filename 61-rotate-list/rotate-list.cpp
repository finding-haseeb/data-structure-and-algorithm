class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int count = 1;
        ListNode* temp = head;

        // Find tail and number of nodes
        while (temp->next != nullptr) {
            temp = temp->next;
            count++;
        }

        ListNode* tail = temp;

        // Important
        k = k % count;

        // No rotation needed
        if (k == 0) {
            return head;
        }

        // Find new tail
        int lastno = count - k;

        temp = head;

        for (int i = 1; i < lastno; i++) {
            temp = temp->next;
        }

        // New head
        ListNode* newhead = temp->next;

        // Break the list
        temp->next = nullptr;

        // Connect old tail to old head
        tail->next = head;

        return newhead;
    }
};