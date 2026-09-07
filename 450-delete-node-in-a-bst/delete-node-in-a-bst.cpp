/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == nullptr) return nullptr;
        
        // search in left side
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        
        // search in right side
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        
        // Node mil gaya
        else {

            // No left child
            if (root->left == nullptr) {
                return root->right;
            }
            
            // No right child
            if (root->right == nullptr) {
                return root->left;
            }

            // Two children

            TreeNode* current = root->right;

            while (current->left != nullptr) {
                current = current->left;
            }

            // Replace
            root->val = current->val;

            // Delete duplicate
            root->right = deleteNode(root->right, current->val);
        }

        return root;
    }
};