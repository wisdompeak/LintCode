class Solution {
public:
    /**
     * return maxium contiguous non-negative subarray sum
     * @param A int整型vector an integer array
     * @return int整型
     */
    int maxNonNegativeSubArray(vector<int>& A) 
    {
        int flag = 1;
        for (auto x: A)
        {
            if (x>=0) flag=0;
        }
        if (flag==1) return -1;
        
        int ret = 0;
        int curMax = 0;
        for (int i=0; i<A.size(); i++)
        {
            if (A[i]<0)
                curMax = 0;
            else
            	curMax = curMax+A[i];
            ret = max(ret, curMax);
        }
        return ret;
    }
};
