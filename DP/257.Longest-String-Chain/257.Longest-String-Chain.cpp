class Solution {
public:
    /**
     * the length of the longest string chain.
     * @param words string字符串vector the list of word.
     * @return int整型
     */
    static bool cmp(string&a, string&b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        vector<int>dp(n,1);
        int ret = 1;
        
        for (int i=1; i<n; i++)
        {
            for (int j=i-1; j>=0; j--)
            {
                if (words[j].size() == words[i].size())
                    continue;
                if (words[j].size() < words[i].size()-1)
                    break;
                if (checkOK(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    ret = max(ret, dp[i]);
                }
            }
        }
        return ret;        
    }
    
    bool checkOK(string&a, string&b)
    {
        int i = 0, j = 0;
        while (i<a.size() && j<b.size())
        {
            if (a[i]==b[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        return (i==a.size()) && (j==b.size()) || (i==a.size() && j==b.size()-1);
    }
};
