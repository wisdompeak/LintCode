class Solution {
public:
    /**
     * @param arr: an integer array
     * @return: return the median array when delete a number
     */
    vector<int> getMedian(vector<int> &arr) 
    {
        int n = arr.size();
        vector<pair<int,int>>nums(n);
        for (int i=0; i<n; i++)
            nums[i] = {arr[i], i};
        sort(nums.begin(), nums.end());
        
        vector<int>idx(n);
        for (int i=0; i<n; i++)
            idx[nums[i].second] = i;
        
        vector<int>rets(n);
        int k = n/2-1;
        for (int i=0; i<n; i++)
        {
            int j = idx[i];
            if (j<=k)
                rets[i] = nums[k+1].first;
            else
                rets[i] = nums[k].first;
        }
        return rets;
        
    }
};
