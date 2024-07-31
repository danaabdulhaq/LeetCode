/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
        vector<int> res;

    vector<int> inorder(TreeNode* root) {

        if (root == NULL) {
            return {};
        }
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);

        return res;
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i] >= res[i+1]) 
            return false;
        }
        return true;
    }


    // return (isValidBST(root->left) >= isValidBST(root->right));
};
