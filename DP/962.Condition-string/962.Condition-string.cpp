​​class Solution {
public:
    /**
     * @param s: a string only contains `a-f`
     * @return: The longest length that satisfies the condition
     */
    int conditionString(string &s) 
    {
        vector<int> a,b;
        for (auto ch:s)
        {
            if (ch=='a')
                a.push_back(1);
            else if (ch=='c')
                a.push_back(2);
            else if (ch=='e')
                a.push_back(3);
            else if (ch=='b')
                b.push_back(1);
            else if (ch=='d')
                b.push_back(2);
            else if (ch=='f')
                b.push_back(3);
        }
        
        int ret = LIS(a) + LIS(b);
        return ret;        
    } 
    
    int LIS(vector<int>& nums)
    {
        int n = nums.size(); 
        auto dp = vector<vector<int>>(n, vector<int>(4,0));
        dp[0][nums[0]] = 1;
        
        for (int i=1; i<n; i++)
        {
            if (nums[i]==1)
            {
                dp[i][1] = dp[i-1][1] + 1;
                dp[i][2] = dp[i-1][2];
                dp[i][3] = dp[i-1][3];
            }
            else if (nums[i]==2)
            {
                dp[i][1] = dp[i-1][1];
                dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + 1;
                dp[i][3] = dp[i-1][3];
            }
            else if (nums[i]==3)
            {
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
                dp[i][3] = max(dp[i-1][1], max(dp[i-1][2], dp[i-1][3])) + 1;
            }
        }
        
        int ret = 1;
        for (int k=1; k<=3; k++)
            ret = max(ret, dp[n-1][k]);
        return ret;
    }
};
