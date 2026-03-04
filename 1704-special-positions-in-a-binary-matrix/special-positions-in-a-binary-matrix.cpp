class Solution {
public:
    bool countrow(vector<vector<int>>& mat, int r, int c){
        int m=mat[0].size();
        for(int j=0;j<m;j++){
            if(mat[r][j]==1 && c!=j ){
                return false;
            }
        }
         return true; 
    }
    bool countcol(vector<vector<int>>& mat, int r, int c){
        int n=mat.size();
        for(int i=0;i<n;i++){
            if(mat[i][c]==1 && i!=r){
                return false;
            }
        }
         return true; 
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && countrow(mat,i,j)
                 && countcol(mat,i,j)){
                
                 count ++;
                }
            }
        }
        return count;
    }
};