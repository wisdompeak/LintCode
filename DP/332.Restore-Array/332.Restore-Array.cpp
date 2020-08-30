class Solution {
public:
    /**
     * @param n: the length of the array.
     * @param l: the least limit for element.
     * @param r: the largest limit for element.
     * @return: return the ways to restore the array.
     */
    int restoreArray(int n, int l, int r) 
    {
        long long M = 1e9+7;
        int k = r-l+1;
        vector<int>count(3,0);
        for (int i=0; i<3; i++)
            count[i] += k/3;
        if (k%3==1)
        {
            count[r%3] += 1;
        }
        else if (k%3==2)
        {
            count[r%3] += 1;
            count[(r-1)%3] += 1;
        }
        
        long long p0 = 1, p1 = 0, p2 = 0;
        for (int i=0; i<n; i++)
        {
            long long p0_temp = p0;
            long long p1_temp = p1;
            long long p2_temp = p2;
            
            p0 = p0_temp * count[0] % M + p1_temp  * count[2] % M + p2_temp * count[1] % M;
            p1 = p0_temp * count[1] % M + p1_temp  * count[0] % M + p2_temp * count[2] % M;
            p2 = p0_temp * count[2] % M + p1_temp  * count[1] % M + p2_temp * count[0] % M;
            p0 %= M;
            p1 %= M;
            p2 %= M;
        }
        return p0;
    }
};
