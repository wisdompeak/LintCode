class Solution {
public:
    /**
     * @param s: The string s
     * @param a: The cost array a
     * @param b: the cost array b
     * @return: Return the minimum cost
     */
    int getAnswer(string &s, vector<int> &a, vector<int> &b) 
    {
        
        priority_queue<int>pq;
        int ans = 0;
        for (int i=0; i<b.size(); i++)
            ans += b[i];
        
        int count = 0;
        int j = 0;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
            {
                count++;
            }
            else if (s[i]==')')
            {
                count--;
            }
            else if (s[i]=='?')
            {
                count--;
                pq.push(b[j]-a[j]);
                j++;
            }
            
            if (count<0)
            {
                if (pq.size()!=0)
                {
                    ans -= pq.top();
                    pq.pop();
                    count = 1;
                }
                else
                    return -1;
            }
        }
        
        if (count>0) return -1;
        
        return ans;
        
    }
};
