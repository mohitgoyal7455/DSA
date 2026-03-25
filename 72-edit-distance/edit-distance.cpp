class Solution {
public:
    int n,m;
    int t[501][501];
    int solve(string s1, string s2,int i,int j){
      if(i==n){
        return m-j;
      }
      if(j==m){
        return n-i;
      }     
      if(t[i][j]!=-1){
        return t[i][j];
      }

      if(s1[i]==s2[j]){
        return t[i][j]=solve(s1,s2,i+1,j+1);
      }
      else{
        int replace=1+solve(s1,s2,i+1,j+1);
        int remove=1+solve(s1,s2,i+1,j);
        int insert=1+solve(s1,s2,i,j+1);
        return t[i][j]=min({replace,remove,insert});
      }
      return -1;


    }
    int minDistance(string s1, string s2) {
         n=s1.length();
        m=s2.length();
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
        
    }
};