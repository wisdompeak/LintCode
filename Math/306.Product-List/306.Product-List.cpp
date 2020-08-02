class Solution {
public:
    /**
     * @param offset: the number of items that the customer has viewed
     * @param n: the number of items that can be displayed on a page
     * @param len1: the length of L1
     * @param len2: the length of L2
     * @return: returns the intervals of goods displayed in L1 and L2
     */
    vector<int> ProductList(int offset, int n, int len1, int len2) 
    {
        int s1 = min(offset, len1);
        int e1 = min(offset+n, len1);
        int s2 = max(offset, len1);
        int e2 = min(offset+n, len1+len2);
        
        vector<int>ret;        
        if (s1 < e1)
        {
            ret.push_back(s1);
            ret.push_back(e1);
        }
        else
        {
            ret.push_back(len1);
            ret.push_back(len1);
        }
        
        if (s2<e2)
        {
            ret.push_back(s2-len1);
            ret.push_back(e2-len1);
        }
        else if (offset+n<=len1)
        {
            ret.push_back(0);
            ret.push_back(0);
        }
        else
        {
            ret.push_back(len2);
            ret.push_back(len2);
        }
        
        return ret;
        
    }
};
