class Solution {
public:
    /**
     * @param L: a string
     * @param R: a string
     * @return: the number of superpalindromes
     */
    int superpalindromesInRange(string &L, string &R) {
        long long a = stoll(L);
        long long b = stoll(R);
        
        int count = 0;
        int flag = 0;
        for (int i=1; i<100000; i++)
        {
            for (int type=0; type<2; type++)
            {
                long long Palin = getPalin(i,type);
                long long SuperPalin = Palin*Palin;
                
                //cout<<Palin<<" "<<SuperPalin<<endl;
                
                if (SuperPalin>=a && SuperPalin<=b && isPalin(SuperPalin))
                    count++;
                
                if (type==1 && SuperPalin>b)
                    flag = 1;
            }
            
            if (flag==1) break;
        }
        return count;
    }
    
    long long getPalin(long long x, int type)
    {
        long long y = x;
        if (type==1)
            x = x/10;
        while (x>0)
        {
            y = y*10+x%10;
            x=x/10;
        }
        return y;
    }
    
    bool isPalin(long long x)
    {
        string s = to_string(x);
        int i = 0;
        int j = s.size()-1;
        while (i<j)
        {
            if (s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
