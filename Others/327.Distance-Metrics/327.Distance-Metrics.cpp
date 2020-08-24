#include <bits/stdc++.h>

class Solution {
public:
    /**
     * an integer array
     * @param a int整型vector an integer array
     * @return int整型vector
     */
    vector<int> getDistanceMetrics(vector<int>& a) 
    {
        unordered_map<int,vector<int>>Map;        
        for (int i=0; i<a.size(); i++)
            Map[a[i]].push_back(i);
        unordered_map<int,int>sum1;
        unordered_map<int,int>sum2;
        unordered_map<int,int>idx;
        
        for (auto kv : Map)
        {
            int x = kv.first;
            vector<int> arr = kv.second;
            idx[x] = 0;
            sum1[x] = 0;
            for (int i=0; i<arr.size(); i++)
                sum2[x] += arr[i]-arr[0];
        }
        
        vector<int>rets;
        for (auto x: a)
        {
            int i = idx[x];
            if (i==0)
                rets.push_back(sum1[x]+sum2[x]);
            else
            {
                sum1[x] += (Map[x][i]-Map[x][i-1])*i;
                sum2[x] -= (Map[x][i]-Map[x][i-1])*(Map[x].size()-i);
                rets.push_back(sum1[x]+sum2[x]);
            }
            idx[x] += 1;            
        }
        
        return rets;
    }
};
