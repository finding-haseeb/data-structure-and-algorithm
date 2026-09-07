class Solution {
    
    TreeNode* build(vector<int>& preorder, int& index, int upperbound) {
        
        if (index == preorder.size() || preorder[index] > upperbound) {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(preorder[index]);
        index++;

        // Left subtree
        node->left = build(preorder, index, node->val);

        // Right subtree
        node->right = build(preorder, index, upperbound);

        return node;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int index = 0;

        return build(preorder, index, INT_MAX);
    }
};