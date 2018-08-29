class Solution {
public:
    /**
     * @param n: the number of sectors
     * @param m: the number of colors
     * @return: The total number of plans.
     */
    long long MOD = 1e9+7;
    
    int getCount(int n, int m) 
    {
        vector<long>Pow(n+1);
        Pow[0] = 1;
        for (int i=1; i<=n; i++)
            Pow[i] = Pow[i-1]*(m-1)%MOD;
            
        return DFS(n,m,Pow);
    }
    
    long long DFS(int n, int m, vector<long>&Pow)
    {
        if (n==1) return m%MOD;
        if (n==2) return m*(m-1)%MOD;
        
        long long result = m*Pow[n-1] - DFS(n-1,m,Pow);
        
        return (result+MOD)%MOD;
    }
};
