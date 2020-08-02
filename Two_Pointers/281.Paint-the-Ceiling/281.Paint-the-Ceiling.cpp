typedef long long ll;
class Solution {
public:
    /**
     * the way can paint the ceiling
     * @param s0 int整型 
     * @param n int整型 
     * @param k int整型 
     * @param b int整型 
     * @param m int整型 
     * @param a long长整型 
     * @return long长整型
     */
    long long painttheCeiling(int s0, int n, int k, int b, int m, long long a) 
    {
        vector<ll>sides(n);
        sides[0] = s0;
        for (int i=1; i<n; i++)
            sides[i]=(k*sides[i-1]+b)% m + 1 + sides[i-1];
        
        ll ret = 0;
        int i=0, j=sides.size()-1;
        for (int i=0; i<sides.size(); i++)
        {
            while (j>=0 && sides[i]*sides[j]>a)
                    j--;
            ret += j+1;
        }
        return ret;        
    }
};
