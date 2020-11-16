class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @param n: max times to swap a 'l' and a 'r'.
     * @return: return if s can transform to t.
     */
    queue<int>q;
    
    bool LRString(string &s, string &t, int n) 
    {
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='l')
                q.push(i);
        }
        
        return helper(s,t,0,n);
    }
    
    bool helper(string &s, string &t, int k, int n) 
    {
        if (k==s.size())
            return true;
        
        if (t[k]=='r')
        {
            if (!q.empty() && q.front()==k) return false;
            return helper(s, t, k+1, n);
        }
        else
        {
            if (q.empty() || q.front()-k > n) return false;
            n -= q.front()-k;
            q.pop();
            return helper(s, t, k+1, n);
        }
    }
};
