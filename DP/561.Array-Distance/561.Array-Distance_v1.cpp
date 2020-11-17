class Solution {
public:
    /**
     * @param A: the array A[] in this problem
     * @return: return the minimum distance
     */
    long long dp[1001][1000];
    
    long long arrayDistance(vector<int> &A) 
    {
        vector<int>B = A;
        sort(B.begin(), B.end());

        for (int j=0; j<B.size(); j++)
            dp[0][j] = 0;
        
        int m = A.size();
        A.insert(A.begin(), 0);
        long long ret = LLONG_MAX;
        
        for (int i=1; i<=m; i++)
        {
            long long curMin = LLONG_MAX/2;
            for (int j=0; j<B.size(); j++)
            {
                curMin = min(curMin, dp[i-1][j]);
                dp[i][j] = curMin + abs(A[i]-B[j]);
                
                if (i==m) ret = min(ret, dp[i][j]);
            }
        }
        
        return ret;
    }
};
