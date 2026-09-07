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

        // Search in left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Search in right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Node found
        else {

            // No left child
            if (root->left == nullptr) {
                return root->right;
            }

            // No right child
            if (root->right == nullptr) {
                return root->left;
            }

            // Node has two children

            // Left subtree ka maximum node find karo
            TreeNode* current = root->left;

            while (current->right != nullptr) {
                current = current->right;
            }

            // Replace root value
            root->val = current->val;

            // Left subtree se duplicate node delete karo
            root->left = deleteNode(root->left, current->val);
        }

        return root;
    }
};