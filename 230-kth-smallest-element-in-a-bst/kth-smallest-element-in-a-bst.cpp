class Solution {
public:

    int count = 0;

    void inorder(TreeNode* root, int k, int &ans) {

        if (root == nullptr) return;

        inorder(root->left, k, ans);

        if (count >= k) return;

        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {

        int ans = -1;

        inorder(root, k, ans);

        return ans;
    }
};