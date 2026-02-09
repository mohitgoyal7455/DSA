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
     vector<int> arr;
     void Inorder(TreeNode*root){
        if(root==NULL){
            return;
        }
        Inorder(root->left);
        arr.push_back(root->val);
        Inorder(root->right);
        }
     TreeNode* buildtree(int l, int r) {  
        if (l > r) return NULL;

        int mid = l + (r - l) / 2;        
        TreeNode* root = new TreeNode(arr[mid]);  
        root->left = buildtree(l, mid - 1);       
        root->right = buildtree(mid + 1, r);      

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        Inorder(root);
        return buildtree(0,arr.size()-1);

        

    }
};