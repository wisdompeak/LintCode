class Solution {
public:
    /**
     * the number of different types of cards
     * @param n int整型 the number
     * @param m int整型 the number of cards in hand
     * @return int整型
     */
    long M = 1e9+7;
    long comb[1001][1001];
    
    long dfs(long m, long n)
    {
        if (comb[m][n]!=-1)
            return comb[m][n];
        if (n==0) return 1;
        if (n==1) return m;        
        if (n>m-n) return dfs(m, m-n);
        long a = dfs(m-1, n-1);        
        long b = dfs(m-1, n);
        comb[m][n] = (a+b)%M;
        return comb[m][n];
    }
    
    int bullCards(int n, int m) 
    {
        for (int i=0; i<=1000; i++)
            for (int j=0; j<=1000; j++)
                comb[i][j] = -1;
        
        long ret = 0;
        for (int a=0; (a<=n && a*4<=m); a++)
            for (int b=0; (a+b<=n && a*4+b*3<=m); b++)
                for (int c=0; (a+b+c<=n && a*4+b*3+c*2<=m); c++)
                {
                    int d = m - (a*4+b*3+c*2);
                    if (a+b+c+d>n) continue;
                    
                    long temp = 1;
                    temp = temp * dfs(n,a) %M;
                    temp = temp * dfs(n-a,b) %M;
                    temp = temp * dfs(n-a-b,c) %M;
                    temp = temp * dfs(n-a-b-c,d) %M;
                    ret = (ret+temp)%M;               
                }
        return ret;
                    
    }
};
