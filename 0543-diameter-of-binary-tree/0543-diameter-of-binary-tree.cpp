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
    int height(TreeNode* root , int& ans){
        if (root == nullptr) return 0 ;

        int lf = height(root->left,ans);
        int rf = height(root->right , ans);

        ans = max(ans , lf + rf);
        return 1 + max(lf, rf);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0 ;
        height(root ,ans);
        return ans;
    }
};