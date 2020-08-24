#include <regex>

class Solution {
public:
    /**
     * 
     * @param formatString string字符串 
     * @param queryStrings string字符串vector 
     * @return bool布尔型vector
     */
    vector<bool> isMatch(string formatString, vector<string>& queryStrings) 
    {        
        string temp;
        for (int i=0; i<formatString.size(); i++)
        {
            if (i<formatString.size()-1 && formatString.substr(i,2)==".*" && temp.size()>=2 && temp.substr(temp.size()-2,2)==".*")
                i++;
            else
                temp.push_back(formatString[i]);
        }
        
        regex pattern = regex(temp);       
        vector<bool>rets;
        for (auto q:queryStrings)
            rets.push_back(regex_search(q, pattern));
        return rets;
    }
};
