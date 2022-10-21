/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    set<TreeNode*> st;
    TreeNode *ans = NULL;
    bool find2(TreeNode* root, int p){
        if(!root) return false;
    
        bool ok = root->val == p || find2(root->left,p) || find2(root->right,p);

        if(ok && !ans && st.find(root)!=st.end()){
            ans = root;
            st.insert(root);
        }
        return ok;
    } 
    bool find1(TreeNode* root, int p){
        if(!root) return false;

        bool ok = root->val == p || find1(root->left,p) || find1(root->right,p);
        if(ok){
            st.insert(root);
        }
        return ok;
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find1(root, p->val);
    
        find2(root, q->val);
        return ans;
    }
};