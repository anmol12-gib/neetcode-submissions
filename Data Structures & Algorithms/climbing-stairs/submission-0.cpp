#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int i, int n, vector<int>& dp){
        if(i==0 || i==1){
            return 1;
        }

        if(dp[i]!=-1) return dp[i];

        int s1 = solve(i-1,n,dp);
        int s2= solve(i-2,n,dp);

        return dp[i]= s1+s2;

    }

public:
    int climbStairs(int n) {

        vector<int> dp(n+1,-1);
        return solve(n,n,dp);
        
    }
};
