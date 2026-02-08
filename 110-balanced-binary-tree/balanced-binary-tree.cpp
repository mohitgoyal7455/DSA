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
// class Solution {
// public:
//     int height(TreeNode*root,bool &ans){
//          if(root==NULL){
//             return 0;
//          }
//          int leftht=height(root->left,ans);
//          int rightht=height(root->right,ans);
         
//          if(abs(leftht-rightht)>1){
//             ans=false;
//             return 0 ;
//          }
//          return max(leftht,rightht)+1;
//     }
//     bool isBalanced(TreeNode* root) {
    
//         bool ans=true;
//         height(root,ans);
//         return ans;
//     }
// };
class Solution {
public:
    int height(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int leftht=height(root->left);
    int rightht=height(root->right);
     return max(leftht,rightht)+1;
    }
bool isBalanced(TreeNode* root) {
    if(root==NULL){
        return true;
    }
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    bool diff=(abs(height(root->left)-height(root->right))<=1);
    if(left&&right&&diff){
        return true;
    }
    else {
        return false;
    }


}
};