class Solution {
public:

    int countNodes(ListNode* head) {

        int n = 0;

        while(head) {
            n++;
            head = head->next;
        }

        return n;
    }

    TreeNode* solve(ListNode*& head, int n) {

        if(n <= 0)
            return NULL;

        TreeNode* left = solve(head, n/2);

        TreeNode* root = new TreeNode(head->val);

        root->left = left;

        head = head->next;

        root->right = solve(head, n - n/2 - 1);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        int n = countNodes(head);

        return solve(head, n);
    }
};