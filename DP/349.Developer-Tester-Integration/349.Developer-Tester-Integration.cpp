class Solution {
public:
    /**
     * @param d:  limit the number of developers that can be seated consecutively with employees of the same type
     * @param t:  limit the number of testers that can be seated consecutively with employees of the same type
     * @param queries: the queries of team size 
     * @return: return the number of ways
     */
    long long dp0[100001];
    long long dp1[100001];
    vector<int> theNumberofWays(int d, int t, vector<int>& queries) 
    {
        long long  sum0 = 1;
        long long  sum1 = 1;
        dp0[0] = 1;
        dp1[0] = 1;
        long long  M = 1e9+7;
        
        for (int i=1; i<=100000; i++)
        {
            dp0[i] = sum1;
            dp1[i] = sum0;

            sum0 = (sum0+dp0[i]) % M;
            sum1 = (sum1+dp1[i]) % M;
            if (i>=t-1)
                sum0 = (sum0 - dp0[i-t+1] + M) % M;
            if (i>=d-1)
                sum1 = (sum1 - dp1[i-d+1] + M) % M; 
        }
        
        vector<int>rets;
        for (auto n : queries)
            rets.push_back((dp0[n]+dp1[n]+M)%M);
        return rets;
    }
};
