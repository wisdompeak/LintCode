class Solution {
public:
    /**
     * @param N:  a positive integer N
     * @return: return a maximum integer less than N, each digit of which must be monotonically increasing.
     */
    string ret;
    
    long long getIncreasingNumber(long long N) 
    {
        if (N>=1000000000)
            return 123456789;
            
        string s = to_string(N);
        string t;
        dfs(s, t, 0, true);
        if (ret!="" && ret!=s) 
            return stoll(ret);
            
        ret = "";
        for (int i=1; i<=s.size()-1; i++)
            ret.push_back(10-i+'0');
        reverse(ret.begin(), ret.end());
        return stoll(ret);
    }
    
    void dfs(string s, string t, int i, bool flag)
    {
        if (ret!="") return;
        if (i==s.size())
        {
            if (s!=t) ret = t;
            return;
        }
        if (t.back()=='9') return;
        
        if (flag==false)
        {
            for (char ch = '9'; ch>=t.back()+1; ch--)
            {
                dfs(s, t+ch, i+1, 0);
            }
        }
        else
        {
            for (char ch = s[i]; ch>=t.back()+1; ch--)
            {
                if (ch<s[i])
                    dfs(s, t+ch, i+1, 0);
                else
                    dfs(s, t+ch, i+1, 1);
            }
        }
    }
};
