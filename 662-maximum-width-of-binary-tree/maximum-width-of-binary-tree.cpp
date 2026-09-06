class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int maxi = 0;

        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();

            // Current level ka original first index
            long long firstIndex = q.front().second;

            long long first = 0;
            long long last = 0;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;
                long long index = q.front().second;

                q.pop();

                // Normalize
                index = index - firstIndex;

                if (i == 0) {
                    first = index;
                }

                if (i == size - 1) {
                    last = index;
                }

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }

            int width = last - first + 1;

            maxi = max(maxi, width);
        }

        return maxi;
    }
};