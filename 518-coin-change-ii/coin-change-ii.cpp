class Solution {
public:
    int dp[301][5001];
    int solve(int i, vector<int>&coins,int amount){
        int n=coins.size();
        if(amount==0){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        if(amount < coins[i]){
            return dp[i][amount]=solve(i+1,coins,amount);
        }
        int take =solve(i,coins,amount-coins[i]);
        int skip=solve(i+1, coins,amount);
        return dp[i][amount]=take+skip;
    }
    int change(int amount,vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,coins,amount);
    }
};