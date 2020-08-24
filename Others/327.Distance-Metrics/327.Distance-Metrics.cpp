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
            
        vector<long long>rets(a.size());
        
        for (auto kv : Map)
        {
            vector<int> pos = kv.second;
            int n = pos.size();
            vector<long long>pre(n);
            vector<long long>suf(n);
            
            pre[0] = 0;
            for (int i=0; i<pos.size(); i++)
                suf[0] += pos[i]-pos[0];
            rets[pos[0]] = pre[0] + suf[0];
            
            for (int i=1; i<pos.size(); i++)
            {
                pre[i] = pre[i-1] + (pos[i]-pos[i-1])*i;
                suf[i] = suf[i-1] - (pos[i]-pos[i-1])*(n-i);
                rets[pos[i]] = pre[i] + suf[i];
            }
        }
        
        return rets;
    }
};
