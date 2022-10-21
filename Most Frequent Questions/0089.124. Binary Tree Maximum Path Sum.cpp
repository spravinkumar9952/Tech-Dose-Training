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
    int ans = -1e9;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        
        int leftMax = max(maxPathSum(root->left), 0);
        int rightMax = max(maxPathSum(root->right), 0);
        ans = max({leftMax, rightMax, })
        return root->val+leftMax+rightMax;
    }
};