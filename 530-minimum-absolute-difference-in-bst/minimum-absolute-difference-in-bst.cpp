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
    TreeNode*prev=NULL;
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL){
            return INT_MAX;
        }
        int ans=INT_MAX;
        if(root->left){
            int leftdis=getMinimumDifference(root->left);
            ans=min(leftdis,ans);
        }
        if(prev!=NULL){
            ans=min(ans,abs(root->val-prev->val));
        }
        prev=root;

        if(root->right){
            int rightdis=getMinimumDifference(root->right);
            ans=min(rightdis,ans);
        }
         return ans;
        
    }
};