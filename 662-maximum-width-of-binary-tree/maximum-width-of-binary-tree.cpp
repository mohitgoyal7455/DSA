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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>Q;
        if(root==NULL){
            return 0;
        }
        Q.push({root,0});
        int maxi=0;
        while(Q.size()>0){
            int s=Q.size();
            unsigned long long stidx=Q.front().second;
            unsigned long long endidx=Q.back().second;
             maxi=max(maxi,(int)(endidx-stidx+1));
            for(int i=0;i<s;i++){
                auto curr=Q.front();
                Q.pop();
                if(curr.first->left){
                 Q.push({curr.first->left,curr.second*2+1});
                }

                if(curr.first->right){
                 Q.push({curr.first->right,curr.second*2+2});
                }
            }
        }
        return maxi;
        
    }
};