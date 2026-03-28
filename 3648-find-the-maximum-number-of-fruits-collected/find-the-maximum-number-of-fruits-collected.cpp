class Solution {
public:
    int n;
    int dp1[1001][1001];
    int dp2[1001][1001];
    int child1collect(vector<vector<int>>& fruits){
        int i=0;
       
        int count=0;
        while(i<n){
            count+=fruits[i][i];
            i++;
        }
        return count;
    }
    int child2collect(int i,int j,vector<vector<int>>& fruits){
        if(i>=n ||j<0||j>=n){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0;
        }
        
        if(i>j || i==j){
            return 0;
        }
        if(dp1[i][j]!=-1){
            return dp1[i][j];
        }
       
        int bottomdia=fruits[i][j]+child2collect(i+1,j+1,fruits);
        int bottomdown=fruits[i][j]+child2collect(i+1,j,fruits);
        int bottomright=fruits[i][j]+child2collect(i+1,j-1,fruits);
        return dp1[i][j]=max({bottomdia,bottomdown,bottomright});
    }

    int child3collect(int i,int j,vector<vector<int>>& fruits){
        if(i<0||i>=n ||j<0||j>=n){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0;
        }
        if(i<j || i==j){
            return 0;
        }
        if(dp2[i][j]!=-1){
            return dp2[i][j];
        }
        
        int bottomdia=fruits[i][j]+child3collect(i+1,j+1,fruits);
        int bottomdown=fruits[i][j]+child3collect(i,j+1,fruits);
        int bottomright=fruits[i][j]+child3collect(i-1,j+1,fruits);
        return dp2[i][j]=max({bottomdia,bottomdown,bottomright}); 
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        int c1=child1collect(fruits);
        int c2=child2collect(0,n-1, fruits);
        int c3=child3collect(n-1,0,fruits);
        
        return c1+c2+c3;
    }
};