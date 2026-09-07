class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        while (root != nullptr) {

            // Left child nahi hai
            if (root->left == nullptr) {

                ans.push_back(root->val);
                root = root->right;
            }

            // Left child hai
            else {

                TreeNode* current = root->left;

                // Left subtree ka rightmost node find karo
                while (current->right != nullptr &&
                       current->right != root) {

                    current = current->right;
                }

                // Thread pehli baar create kar rahe hain
                if (current->right == nullptr) {

                    ans.push_back(root->val);

                    current->right = root;

                    root = root->left;
                }

                // Thread already exist karta hai
                else {

                    current->right = nullptr;

                    root = root->right;
                }
            }
        }

        return ans;
    }
};