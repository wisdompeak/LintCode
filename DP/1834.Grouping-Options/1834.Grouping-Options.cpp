class Solution {
public:
    /**
     * @param n: the number of people
     * @param m: the number of groups
     * @return: the number of grouping options
     */
    long long groupingOptions(int n, int m) 
    {
        if (n==m) return 1;
        if (n<m) return 0;
        
        long long dp[n+1][m+1] = {0};
        
        for (int j=0; j<=n; j++)
            dp[0][j] = 1;
        for (int i=0; i<=n; i++)
            dp[i][1] = 1;
            
        
        for (int i=2; i<=n; i++)
            for (int j=2; j<=m; j++)
            {
                dp[i][j] = 0;
                for (int t=(j==m)?1:0; t*j<=i; t++)
                    dp[i][j] += dp[i-t*j][j-1];                    
            }
        
        return dp[n][m];
    }
};
