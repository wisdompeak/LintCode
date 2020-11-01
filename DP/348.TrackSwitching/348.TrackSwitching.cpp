class Solution {
public:
    /**
     * @param obstacles: the tracks which obstacles are settled on.
     * @return: return the minimum times to switch the track.
     */
    int dp[50002][4];
    int trackSwitching(vector<int> &obstacles) 
    {
        int n = obstacles.size();
        dp[0][1] = 1;
        dp[0][2] = 0;
        dp[0][3] = 1;
        for (int i=0; i<n; i++)
        {
            int obs = obstacles[i];

            for (int j=1; j<=3; j++)
            {
                if (j!=obs)
                    dp[i+1][j] = dp[i][j];
                else
                    dp[i+1][j] = INT_MAX/2;
            }
            
            for (int j=1; j<=3; j++)
                dp[i+1][obs] = min(dp[i+1][obs], dp[i+1][j]+1);
                
            // cout<<i<<endl;
            // for (int j=1; j<=3; j++)
            //     cout<<dp[i+1][j]<<" ";
            // cout<<endl;
            
        }
        
        int ret = INT_MAX/2;
        for (int j=1; j<=3; j++)
            ret = min(ret, dp[n][j]);
        return ret;
    }
};
