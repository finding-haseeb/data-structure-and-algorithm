class Solution {
public:

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (left != nullptr && right != nullptr) {

            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        // Remaining nodes
        if (left != nullptr) {
            temp->next = left;
        }
        else {
            temp->next = right;
        }

        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {

        // 0 or 1 node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list
        ListNode* right = slow->next;
        slow->next = nullptr;

        ListNode* left = head;

        // Sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge
        return merge(left, right);
    }
};