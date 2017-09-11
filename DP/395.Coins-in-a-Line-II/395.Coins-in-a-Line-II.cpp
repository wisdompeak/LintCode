class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values)
    {
        int N=values.size();
        if (N<=2) return true;
        
        vector<int>dp=vector<int>(N+1,0);
        
        dp[N-1]=values[N-1];
        dp[N-2]=values[N-1]+values[N-2];
        dp[N-3]=values[N-3]+values[N-2];
        
        for (int i=N-4; i>=0; i--)
        {
            int dp1= values[i]+min(dp[i+2],dp[i+3]);
            int dp2= values[i]+values[i+1]+min(dp[i+3],dp[i+4]);
            dp[i]=max(dp1,dp2);
        }
        
        int sum=0;
        for (int i=0; i<N; i++)
            sum+=values[i];
            
        return dp[0]>sum-dp[0];
    }
};
