
  /*Definition for a binary tree node.
  
  
   struct TreeNode {
     int val;
   TreeNode *left;
       TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 */
class Solution {
public:
    int height(TreeNode* root){
        if (root == nullptr) return 0;
        int leftHeight= height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight , rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        
        if (root == nullptr) return true;
        int lf = height(root->left);
        int rf = height(root->right);

        int diff = abs(lf-rf);
        if (diff > 1) return false;
        int a = isBalanced(root->left);
        int b = isBalanced(root->right);
        return a && b ;

    }
    
};