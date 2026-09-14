class Solution {
private:
    int solve(int i, vector<int>& cost, vector<int>& dp) {
        if (i == 0 || i == 1) {
            return cost[i];
        }

        if (dp[i] != -1)
            return dp[i];

        int s1 = solve(i - 1, cost, dp);
        int s2 = solve(i - 2, cost, dp);

        return dp[i] = cost[i] + min(s1, s2);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, -1);

        return min(solve(n - 1, cost, dp),
                   solve(n - 2, cost, dp));
    }
};