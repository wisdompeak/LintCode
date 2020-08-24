#include <bits/stdc++.h>

class Solution {
public:
    /**
     * if knight is attacked please return true，else return false
     * @param queen int整型vector<vector<>> queen‘coordinate
     * @param knight int整型vector<vector<>> knight‘coordinate
     * @return bool布尔型vector
     */
    vector<bool> isAttacked(vector<vector<int> >& queen, vector<vector<int> >& knight) 
    {
        unordered_set<int>row;
        unordered_set<int>col;
        unordered_set<int>diag1;
        unordered_set<int>diag2;
        
        for (auto x: queen)
        {
            row.insert(x[0]);
            col.insert(x[1]);
            diag1.insert(x[1]-x[0]);
            diag2.insert(x[0]+x[1]);
        }
        vector<bool>rets;
        for (auto x:knight)
        {
            if (row.find(x[0])!=row.end())
                rets.push_back(true);
            else if (col.find(x[1])!=col.end())
                rets.push_back(true);
            else if (diag1.find(x[1]-x[0])!=diag1.end())
                rets.push_back(true);
            else if (diag2.find(x[0]+x[1])!=diag2.end())
                rets.push_back(true);
            else
                rets.push_back(false);
        }
        return rets;
    }
};
