class Solution {
public:
    /**
     * @param l: left
     * @param r: right
     * @return: return the number of lucky number in [l,r]
     */
    void dfs(string& s, long d, int pos, vector<long>&rets)
    {        
        if (pos == s.size())
        {
            rets.push_back(d);
            return;
        }
        
        int diff = s[pos]-'0';
        int low = d % 10;
        if (low-diff>=0)
        {
            dfs(s, d*10 + (low-diff), pos+1, rets);
        }
        if (low+diff<=9)
        {
            dfs(s, d*10 + (low+diff), pos+1, rets);
        }
    }
    
    
    int theNumberofLuckyNumber(int l, int r) 
    {
        unordered_set<long>Set;
        queue<long>q;
        q.push(7);
        
        while (!q.empty())
        {
            long cur = q.front();
            q.pop();
            string s = to_string(cur);
            if (cur > 1e9 || s.size() == 9) 
                continue;

            // expand current number by adding one digit, starting with d
            vector<long>next;
            for (int d=1; d<=9; d++)
            {
                dfs(s, d, 0, next);
            }
            // a special case: e.g. 108->1108 by adding the same digit at the head
            int high = cur;
            while (high>=10) 
                high /= 10;
            if (cur!=7)
                next.push_back(cur+high*pow(10, s.size()));
            
            // import new numbers into the queue
            for (auto x: next)
            {
                if (Set.find(x)!=Set.end()) 
                    continue;                    
                q.push(x);
                Set.insert(x);
            }
        }
        
        vector<long>p({7});
        for (auto x: Set)        
            p.push_back(x);
        sort(p.begin(), p.end());
        return upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l);
    }
};
