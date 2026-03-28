class Solution {
public:
    int n,m;
    int t[1001][1001];
    int solve(int i,int j,vector<vector<int>>& dungeon){
        if( i>=n ||j>=m){
            return INT_MAX;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==n-1 && j==m-1){
            if(dungeon[i][j]<0){
                return t[i][j]=abs(dungeon[i][j])+1;
            }
             else{
                return t[i][j]=1;
            }
        }
        int right=solve(i,j+1,dungeon);
        int down=solve(i+1,j,dungeon);
        int result=min(right,down)-dungeon[i][j];
        return t[i][j]=(result>0)? result:1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
         n=dungeon.size();
         m=dungeon[0].size();
         memset(t,-1,sizeof(t));
        return solve(0,0,dungeon);
        
    }
};