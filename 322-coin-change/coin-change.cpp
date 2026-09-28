class Solution {
public:
    int dp[13][10001];

    int solve(int i, vector<int>& coins, int amount) {
        int n = coins.size();

        if (amount == 0) {
            return 0;
        }

        if (i == n) {
            return 1e9;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        if (amount < coins[i]) {
            return dp[i][amount] = solve(i + 1, coins, amount);
        }

        int take = 1 + solve(i, coins, amount - coins[i]);
        int skip = solve(i + 1, coins, amount);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));

        int ans = solve(0, coins, amount);

        return ans >= 1e9 ? -1 : ans;
    }
};