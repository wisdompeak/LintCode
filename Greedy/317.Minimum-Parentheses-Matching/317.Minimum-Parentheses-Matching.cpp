class Solution {
public:
    /**
     * @param s: The original string
     * @return:  the lexicographical order of the smallest parentheses to match the legal sequence
     */
    string minimumParenthesesMatching(string &s) 
    {
        deque<int>pos;

        int count = 0;
        for (int j=0; j<s.size(); j++)
        {
            if (s[j]=='*')
            {
                pos.push_back(j);
                continue;
            }
            else if (s[j]=='(')
                count++;
            else
                count--;
            
            if (count<0)
            {
                count = 0;
                if (pos.size()>0)
                {
                    s[pos.front()] = '(';
                    pos.pop_front();
                }
                else
                    return "No solution!";
            }
        }
        
        count = 0;
        pos.clear();
        for (int j=s.size()-1; j>=0; j--)
        {
            if (s[j]=='*')
            {
                pos.push_back(j);
                continue;
            }
            else if (s[j]==')')
                count++;
            else
                count--;
            
            if (count<0)
            {
                count=0;
                if (pos.size()>0)
                {
                    s[pos.front()] = ')';
                    pos.pop_front();
                }
                else
                    return "No solution!";
            }
        }
        
        string ret;
        for (int i=0; i<s.size(); i++)
        if (s[i]!='*') ret.push_back(s[i]);
        
        return ret;

    }
};
