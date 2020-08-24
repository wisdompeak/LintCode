class Solution {
public:
    /**
     * @param a: an integer posay
     * @return: an integer posay
     */
    vector<long long> getDistanceMetrics(vector<int> &a) 
    {
        unordered_map<int,vector<int>>Map;        
        for (int i=0; i<a.size(); i++)
            Map[a[i]].push_back(i);
        unordered_map<int,long long>pre;
        unordered_map<int,long long>suf;
        unordered_map<int,int>idx;
        
        for (auto kv : Map)
        {
            int x = kv.first;
            vector<int> pos = kv.second;
            idx[x] = 0;
            pre[x] = 0;
            for (int i=0; i<pos.size(); i++)
                suf[x] += pos[i]-pos[0];
        }
        
        vector<long long>rets;
        for (auto x: a)
        {
            int i = idx[x];
            if (i==0)
                rets.push_back(pre[x]+suf[x]);
            else
            {
                pre[x] += (Map[x][i]-Map[x][i-1])*i;
                suf[x] -= (Map[x][i]-Map[x][i-1])*(Map[x].size()-i);
                rets.push_back(pre[x]+suf[x]);
            }
            idx[x] += 1;            
        }
        
        return rets;
    }
};
