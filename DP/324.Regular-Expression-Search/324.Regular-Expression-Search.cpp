#include <regex>
class Solution {
public:
    /**
     * @param formatString: the format string
     * @param queryStrings: the query strings
     * @return: judge isMatch
     */
    bool canSearch(string p, string s) // if can search pattern p in string s (starting from the beginning but ending at any position)
    {
        int M = s.size();
        int N = p.size();
        s = "0"+s;
        p = "0"+p;
        auto dp = vector<vector<int>>(M+1,vector<int>(N+1,0));
        dp[0][0] = 1;
        for (int j=2; j<=N; j++)
        {
            if (p[j]=='*'||p[j]=='?') dp[0][j]=dp[0][j-2];
        }
    
        for (int j=1; j<=N; j++)
            for (int i=1; i<=M; i++)
            {
                if (isalpha(p[j]))
                {
                    dp[i][j] = (s[i]==p[j] && dp[i-1][j-1]);
                }
                else if (p[j]=='.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j]=='*')
                {
                    bool temp1 = dp[i][j-2];
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='?')
                {
                    bool temp1 = dp[i][j-2];
                    bool temp2 = dp[i][j-1];
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='+')
                {
                    bool temp1 = dp[i][j-1];
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='$')
                {
                    dp[i][j] = (dp[i][j-1] && i==M);
                }
                    
                // cout<<i<<"  "<<j<<" "<<dp[i][j]<<endl;
                if (j==N && dp[i][j]==true)
                    return true;
            }
        return false;
        
    }
    
    vector<bool> isMatch(string &formatString, vector<string> &queryStrings) {        
        vector<bool> ans;
        if (formatString[0]=='^')
        {
            formatString = formatString.substr(1);
            for (auto queryString : queryStrings)
            {
                ans.push_back(canSearch(formatString, queryString));
            }            
        }
        else
        {
            for (auto queryString : queryStrings)
            {
                int flag = 0;
                for (int start = 0; start < queryString.size(); start++)
                {
                    if (canSearch(formatString, queryString.substr(start)))
                    {
                        flag = 1;
                        ans.push_back(true);
                        break;
                    }                    
                }
                if (flag==0) {
                    ans.push_back(false);
                }
            }        
        }    
        return ans;
    }
};
