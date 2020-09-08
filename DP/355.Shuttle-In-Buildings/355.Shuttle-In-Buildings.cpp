class Solution {
public:
    /**
     * @param heights: the heights of buildings.
     * @param k: the vision.
     * @param x: the energy to spend of the first action.
     * @param y: the energy to spend of the second action.
     * @return: the minimal energy to spend.
     */
    long long shuttleInBuildings(vector<int> &heights, int k, int x, int y) 
    {
        stack<int>Stack;
        int n = heights.size();
        vector<int>nextHigher(n, -1);
        for (int i=0; i<heights.size(); i++)
        {
            while (!Stack.empty() && i-Stack.top() <= k && heights[i] > heights[Stack.top()])
            {
                nextHigher[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        
        vector<vector<int>>prev(n);
        for (int i=0; i<n; i++)
        {
            if (nextHigher[i]!=-1)
                prev[nextHigher[i]].push_back(i);
        }
        
        vector<long long>dp(n);
        dp[0] = 0;
        for (int i=1; i<n; i++)
        {
            dp[i] = LLONG_MAX;
            for (auto last: prev[i])
                dp[i] = min(dp[i], dp[last] + x);
            if (i-1>=0)
                dp[i] = min(dp[i], dp[i-1] + y);
            if (i-2>=0)
                dp[i] = min(dp[i], dp[i-2] + y);
        }
        
        return dp[n-1];
        
        
    }
};
