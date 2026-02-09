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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>Q;
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        Q.push(root);
        
        while(!Q.empty()){
            vector<int>l;
            int s=Q.size();
            for(int i=0;i<s;i++){
            TreeNode* curr=Q.front();
            Q.pop();
            l.push_back(curr->val);
            
            
         if(curr->left !=NULL){
             Q.push(curr->left);
         }   
         if(curr->right !=NULL){
            Q.push(curr->right);}
         }
         v.push_back(l);
        }
         return v;

        
    }
};