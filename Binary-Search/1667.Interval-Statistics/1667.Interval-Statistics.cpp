class Solution {
public:
    /**
     * @param arr: the 01 array
     * @param k: the limit 
     * @return: the sum of the interval
     */
    long long intervalStatistics(vector<int> &arr, int k) 
    {
        
        vector<long>Count;
        long count = 0;
        for (int i=0; i<arr.size(); i++)
        {
            if (arr[i]==0) count++;
            Count.push_back(count);
        }
        
        vector<long>cumSum;
        long cum = 0;
        long result = 0;
        
        for (int i=0; i<arr.size(); i++)
        {
            cum+=arr[i];
            cumSum.push_back(cum);
            if (arr[i]==1) continue;
            
            auto iter = lower_bound(cumSum.begin(),cumSum.end(),cum-k);
            int pos = iter-cumSum.begin();
            
            if (arr[pos]==1)
                result+=Count[i]-Count[pos];
            else
                result+=Count[i]-Count[pos]+1;            
        }
        return result;            
    }
};
