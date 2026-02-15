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
     int preorder=0;
    int kthSmallest(TreeNode* root, int k) {
        
        if(root==NULL){
            return -1;
        }
        if(root->left){
            int leftnode=kthSmallest(root->left,k);
            if(leftnode!=-1){
                return leftnode;
            }
        }
        if(preorder+1==k){
            return root->val;
        }
        preorder=preorder+1;

        if(root->right){
            int rightnode=kthSmallest(root->right,k);
            if(rightnode!=-1){
                return rightnode;
            }
        }
        return -1;
    }
};