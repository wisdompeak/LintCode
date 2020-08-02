#include <bits/stdc++.h>

class Solution {
public:
    /**
     * return the spacing of the closest wordA and wordB.
     * @param words string字符串vector the words given.
     * @param wordA string字符串 the first word you need to find.
     * @param wordB string字符串 the second word you need to find.
     * @return int整型
     */
    int wordSpacing(vector<string>& words, string wordA, string wordB) 
    {
        unordered_map<string,vector<int>>Map;
        for (int i=0; i<words.size(); i++)
            Map[words[i]].push_back(i);
        
        if (Map.find(wordA)==Map.end() || Map.find(wordB)==Map.end())
            return -1;
        
        return helper(Map[wordA], Map[wordB]);
        // write code here
    }
    
    int helper(vector<int>&A, vector<int>&B)
    {
        if (B.size()>A.size()) return helper(B, A);
        int ret = INT_MAX;
        for (auto b: B)
        {
            auto iter = lower_bound(A.begin(), A.end(), b);
            int idx = iter-A.begin();
            if (idx==0)
                ret = min(ret, abs(A[idx]-b));
            else
                ret = min(ret, min(abs(A[idx]-b), abs(A[idx-1]-b)));
        }
        return ret;
    }
};
