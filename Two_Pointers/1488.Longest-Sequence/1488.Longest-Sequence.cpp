class Solution {
public:
    /**
     * @param a: The array a
     * @return: Return the maximum length
     */
    int getAnswer(vector<int> &a) 
    {
        int N = a.size();
        auto dp=vector<vector<int>>(N,vector<int>(N,0));
        sort(a.begin(),a.end());
        int result = 0;
        
        for (int i=0; i<N; i++)
        {
            int left = i-1;
            int right = i+1;
            int target = a[i]*2;
            while (left>=0 && right<N)
            {
                if (a[left]+a[right]<target)
                    right++;
                else if (a[left]+a[right]>target)
                    left--;
                else
                {
                    dp[i][right] = dp[left][i]+1;
                    result = max(result,dp[i][right]);
                    left--;
                    right++;
                }
            }
        }
        
        return result+2;
    }
};
