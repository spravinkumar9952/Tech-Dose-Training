Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preOrder(TreeNode* root, string &ser){
        if(root==NULL){
            ser += "NULL ";
            return ;
        }
        ser += to_string(root->val)+" ";
        preOrder(root->left, ser);
        preOrder(root->right, ser);
    }
    string serialize(TreeNode* root) {
        string ser = "";
        preOrder(root, ser);
        // cout << ser << endl;
        return ser;
    }

    // Decodes your encoded data to tree.
    int ind = 0;
    TreeNode* buildTree(vector<string>&arr){
        // cout << ind << " ";
        if(ind>=arr.size() || arr[ind]=="NULL"){
            ind++;
            return NULL;
        }
        TreeNode *newNode = new TreeNode(stoi(arr[ind++]));
        newNode -> left = buildTree(arr);
        newNode -> right = buildTree(arr);
        return newNode;
    }
    TreeNode* deserialize(string data) {
        vector<string> arr;
        stringstream ss(data);
        string word;
        while(ss >> word){
            arr.push_back(word);
        }
        // cout << arr.size() << endl;
        return buildTree(arr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));