#include <bits/stdc++.h>

class Solution {
public:
    /**
     * 
     * @param str string字符串 the prefix notation.
     * @return string字符串
     */
    string prefixNotationToPostfixNotation(string str) {        
        stack<string>oper;
        stack<vector<string>>num;
        vector<string> cur;
        string ret;
        for (int i=0; i<str.size(); i++)
        {
            int j = i;
            while (j<str.size() && str[j]!=' ')
                j++;
            string s = str.substr(i, j-i);

            if (s=="+" || s=="-" || s=="*" || s=="/")
            {
                oper.push(s);
                num.push(cur);
                cur = {};
            }                
            else
            {
                ret += s + " ";
                cur.push_back(s);

                while (cur.size()==2)            
                {                
                    ret += oper.top() + " "; 

                    cur = num.top();
                    cur.push_back("#");
                    num.pop();
                    oper.pop();
                }            
            }

            i = j;
        }

        ret.pop_back();
        return ret;

    }
};
