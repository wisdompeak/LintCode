long M = 1e9+7;
int bullCards(int n, int m) 
{
    auto dp = vector<vector<long>>(n+1,vector<long>(m+1,0));
    dp[0][0] = 1;
    for (int i=1; i<=n; i++)   
    {
        dp[i][0] = 1;
        for (int j = 1; j <= min(m,4*i); j++)
        {
            for (int k=0; k<=min(j,4); k++)
                dp[i][j] = (dp[i][j] + dp[i-1][j-k])%M;
        }
    }
    return dp[n][m];                    
}
