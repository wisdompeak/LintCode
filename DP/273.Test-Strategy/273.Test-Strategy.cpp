
class Solution {
public:
    /**
     * Return the maximum number of points you can get.
     * @param p int整型vector The time you choose to do part of the problem.
     * @param part int整型vector The points you choose to do part of the problem.
     * @param f int整型vector The time you choose to do the whole problem.
     * @param full int整型vector The points you choose to do the whole problem.
     * @return int整型
     */
    int exam(vector<int>& p, vector<int>& part, vector<int>& f, vector<int>& full) 
    {
        vector<int>dp(121,-1);
        dp[0] = 0;
        for (int i=0; i<p.size(); i++)
        {
            auto dp_temp = dp;
            for (int t=0; t<=120; t++)
            {
                dp[t] = dp_temp[t];
                if (t>=p[i] && dp_temp[t-p[i]]!=-1) dp[t] = max(dp[t], dp_temp[t-p[i]]+part[i]);
                if (t>=f[i] && dp_temp[t-f[i]]!=-1) dp[t] = max(dp[t], dp_temp[t-f[i]]+full[i]);                
            }
        }
        int ret = 0;
        for (int i=0; i<=120; i++)
            ret = max(ret, dp[i]);
        return ret;
        
    }
};
