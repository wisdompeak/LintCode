class Solution {
public:
    /**
     * @param s: a string.
     * @return: return the values of all the intervals.
     */
    long long suffixQuery(string &s) 
    {
        long long ret = 0;
        int n = s.size();
        
        auto dp = vector<vector<long long>>(n, vector<long long>(n));
        for (int i=0; i<n; i++)
        {
            dp[i][i] = 1;
            ret += 1;
        }
        
        for (long long len = 2; len <= n; len++)
            for (long long i=0; i+len-1<n; i++)
            {
                long long j = i+len-1;
                if (s[i]==s[j])
                {
                    dp[i][j] = dp[i+1][j-1]+1;
                    if (dp[i][j]*2 == j-i+1 || dp[i][j]*2-1 == j-i+1 )
                        ret += j-i+1;
                    else
                        ret += dp[i][j];
                }
            }
        
        return ret;
    }
};
