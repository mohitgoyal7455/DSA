class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
     
     bfs(image,sr,sc,newColor);
     return image;
        
        
    }
    void bfs(vector<vector<int>>& image, int sr, int sc,int & newColor){
        int n=image.size();
        int m=image[0].size();
        int inicol=image[sr][sc];
        if (inicol == newColor) return;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        
        int delrow[]={0,-1,0,1};
        int delcol[]={1,0,-1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol >=0 && ncol<m &&
                    image[nrow][ncol]==inicol){
                        image[nrow][ncol]=newColor;
                        q.push({nrow,ncol});
                    }
            }
        }
    }
};