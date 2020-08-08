class Solution {
public:
    /**
     * @param a: the array you need to operate.
     * @param b: the target array.
     * @return: return the minimum number of operations.
     */
    int minimumInsertion(vector<int> &a, vector<int> &b) 
    {
        unordered_map<int,int>Map;
        int n = a.size();
        for (int i=0; i<n; i++)
        {
            Map[b[i]] = i;
        }
        
        int len = 1;
        int maxLen = 1;
        for (int i=1; i<n; i++)
        {
            if (Map[a[i]]>Map[a[i-1]])
                len += 1;
            else
                len = 1;
            maxLen = max(len, maxLen);
        }
        
        return n-maxLen;
    }
};
