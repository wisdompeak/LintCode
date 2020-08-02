
#include <bits/stdc++.h>

class Solution {
public:
    /**
     * calculate the max value
     * @param meeting int整型vector<vector<>> the meetings
     * @param value int整型vector the value
     * @return int整型
     */
    int maxValue(vector<vector<int> >& meeting, vector<int>& value) 
    {
        int n = meeting.size();        
        unordered_map<int,vector<vector<int>>>Map;
        for (int i=0; i<n; i++)
            Map[meeting[i][1]].push_back({meeting[i][0], value[i]});
        
        vector<int>dp(50001,0);
        for (int i=1; i<=50000; i++)
        {
            dp[i] = dp[i-1];
            for (auto x : Map[i])
            {
                dp[i] = max(dp[i], dp[x[0]]+x[1]);
            }            
        }
        
        return dp[50000];
    }
};
