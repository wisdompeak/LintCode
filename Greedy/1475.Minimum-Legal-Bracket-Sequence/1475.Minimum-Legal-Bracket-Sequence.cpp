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
        
        int lower = 0;
        int upper = 0;
        int leftMustCount = 0;
        int j = 0;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
            {
                lower++;
                upper++;
            }
            else if (s[i]==')')
            {
                lower--;
                upper--;
            }
            else if (s[i]=='?')
            {
                lower--;
                upper++;
                pq.push(b[j]-a[j]);
                j++;
            }
            
            if (lower<0)
            {
                ans -= pq.top();
                pq.pop();
                lower = 1;
                leftMustCount++;
            }
            
            //cout<<s[i]<<" "<<lower<<" "<<upper<<" "<<leftMustCount<<" "<<ans<<endl;

            if (upper<0)
                return -1;
        }
        
        if (lower>0) return -1;
        
        return ans;
        
    }
};
