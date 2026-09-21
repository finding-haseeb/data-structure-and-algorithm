class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        ListNode* curr = list1;

        // Find node at a-1
        for(int i = 0; i < a - 1; i++) {
            prev = prev->next;
        }

        // Find node at b
        curr = prev;
        for(int i = a - 1; i < b; i++) {
            curr = curr->next;
        }

        // Connect a-1 node to list2
        prev->next = list2;

        // Find last node of list2
        ListNode* tail = list2;
        while(tail->next != NULL) {
            tail = tail->next;
        }

        // Connect list2 to b+1 node
        tail->next = curr->next;

        return list1;
    }
};