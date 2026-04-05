class Solution {
private:
void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& ans,int newColor,int inicol){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
if(nrow>=0 && nrow <n && ncol >=0 && ncol <m && image[nrow][ncol]==inicol && ans[nrow][ncol]!=newColor){
                
                dfs(nrow,ncol,image,ans,newColor,inicol);
            }
        }
    }
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int inicol=image[sr][sc];
                                    vector<vector<int>>ans=image;
                                    dfs(sr,sc,image,ans,newColor,inicol);
                                    return ans;
        
    }
};