class Solution {
public:
    /**
     * @param n: the number of steps
     * @param num: the maximum step Ming can run up at the ith step
     * @return: Return the number of ways to run up the stairs
     */
    
    long long Solve(int n, vector<int> &num) 
    {
        int dp[1000000+2];
        int mod = 1e9 + 7;
        for (int i = 0; i <= n; i++) 
            dp[i] = 0;
        dp[0] = 1;
        dp[1] = -1;
        
        int res = 0;
        for (int i = 0; i < n; i++) 
        {
            res = (res + dp[i]) % mod;
            int L = i + 1;
            int R = min(n + 1, i + num[i] + 1);
            dp[L] = (dp[L] + res) % mod;
            dp[R] = (dp[R] - res) % mod;
        }
        res = (res + dp[n]) % mod;
        return res;
    }
};
