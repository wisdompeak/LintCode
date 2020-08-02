class Solution {
public:
    /**
     * return the minimum square value of the maximum difference
     * @param n int整型 the number of buckets
     * @param k int整型 the maximum times of operations
     * @param A int整型vector the number of balls in each bucket
     * @param W int整型vector the maximum capacity of each bucket
     * @return int整型
     */

    int getAns(int n, int k, vector<int>& A, vector<int>& W) 
    {
        int left = 0, right = 100;
        while (left<right)
        {
            int mid = left+(right-left)/2;
            if (checkOK(mid, n, k, A, W))
                right = mid;
            else
                left = mid+1;        
        }
        return left*left;

    }

    bool checkOK(int diff, int n, int k, vector<int>& A, vector<int>& W)
    {
        int dp[100][101];

        for (int a=0; a<=W[0]; a++)
            dp[0][a] = abs(a-A[0]);

        for (int i=1; i<n; i++)
            for (int a=0; a<=W[i]; a++)
            {
                dp[i][a] = INT_MAX/2;
                for (int b = 0; b<=W[i-1]; b++)
                {                
                    if (abs(a-b)>diff) continue;
                    dp[i][a] = min(dp[i][a], dp[i-1][b]+abs(A[i]-a));                 
                }                    
            }

        int ret = INT_MAX;        
        for (int a = 0; a <= W[n-1]; a++)
            ret = min(ret, dp[n-1][a]);

        return ret<=k;
    }    
};
