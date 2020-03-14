class Solution {
public:
    /**
     * @param n: the number of people
     * @param m: the number of groups
     * @return: the number of grouping options
     */
    long long groupingOptions(int n, int m) 
    {
        auto dp = vector<vector<long long>>(n+1, vector<long long>(m+1,0));
        dp[0][0] = 1;
        for (int j=1; j<=m; j++)
            dp[0][j] = 1;
        
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                dp[i][j] = 0;
                for (int t=(j==m)?1:0; t*j<=i; t++)
                    dp[i][j] += dp[i-t*j][j-1];
            }            
        return dp[n][m];        
    }
};
