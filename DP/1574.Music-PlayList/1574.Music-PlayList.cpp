class Solution {
public:
    /**
     * @param n: the number of on his mobile phone
     * @param m: in the middle of two songs, there are at least m other songs
     * @param p: the number of songs he can listen to
     * @return: the number of playlists
     */
    int getAns(int n, int m, int p) 
    {
        auto dp = vector<vector<long>>(p+1,vector<long>(n+1));
        int MOD = 1e9+7;
        
        dp[1][1] = n;
        
        for (int i=2; i<=p; i++)
            for (int j=1; j<=n; j++)
            {
                if (j>m)
                {
                    dp[i][j] += dp[i-1][j]*(j-m);
                    dp[i][j]%=MOD;
                }
                if (n>(j-1))
                {
                    dp[i][j] += dp[i-1][j-1]*(n-(j-1));
                    dp[i][j]%=MOD;
                }
                
            }
            
        return dp[p][n];
    }
};
