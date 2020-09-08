class Solution {
public:
    /**
     * @param lengths: the lengths of sticks at the beginning.
     * @return: return the minimum number of cuts.
     */
    int makeEquilateralTriangle(vector<int> &lengths) 
    {
        sort(lengths.begin(), lengths.end());
        int n = lengths.size();
        for (int i=2; i<n; i++)
        {
            if (lengths[i]==lengths[i-1] && lengths[i]==lengths[i-2])
                return 0;
        }
        
        for (int i=1; i<n; i++)
        {
            if (lengths[i]==lengths[i-1] && i!=n-1)
                return 1;
        }
        
        unordered_set<int>Set(lengths.begin(), lengths.end());
        for (int i=0; i<n; i++)
        {
            if (Set.find(lengths[i]*2)!=Set.end())
                return 1;
        }
        
        return 2;
    }
};
