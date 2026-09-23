class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1 != NULL) {
            temp->next = list1;
        }

        if (list2 != NULL) {
            temp->next = list2;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        if (n == 0) {
            return NULL;
        }

        while (n > 1) {

            int index = 0;

            for (int i = 0; i < n; i += 2) {

                if (i + 1 < n) {
                    lists[index] = mergeTwoLists(lists[i], lists[i + 1]);
                } else {
                    lists[index] = lists[i];
                }

                index++;
            }

            n = index;
        }

        return lists[0];
    }
};