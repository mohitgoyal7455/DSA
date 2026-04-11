class Solution {
public:
    int solve(string& s,string& t,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i == m || j == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            dp[i][j] = 1 + solve(s,t,i+1,j+1,m,n,dp);
        }else{
            dp[i][j] = max(solve(s,t,i+1,j,m,n,dp),solve(s,t,i,j+1,m,n,dp));
        }

        return dp[i][j];
    }

    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        
        int m = s.length();
        int n = t.length();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        int ans = solve(s,t,0,0,m,n,dp);

        return m - ans;
    }
};