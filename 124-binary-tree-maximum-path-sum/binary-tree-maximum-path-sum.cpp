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
    int solve( TreeNode* node, int & maxi) {
        if ( node == nullptr) return 0;

        int leftsum= max ( 0 , solve( node->left , maxi));
        int rightsum = max( 0 , solve ( node -> right , maxi));

        maxi= max( maxi , node->val + leftsum + rightsum );

        return node -> val + max ( leftsum , rightsum );
    }

public:
    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        solve( root , maxi);
        return maxi;
        
    }
};