class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) 
    {
        vector<int>nums({1});
        int idx2=0, idx3=0, idx5=0;
        int count = 1;
        while (count<n)
        {
            int a = nums[idx2]*2;
            int b = nums[idx3]*3;
            int c = nums[idx5]*5;
            int k = min(a,min(b,c));
            if (a==k) idx2++;
            if (b==k) idx3++;
            if (c==k) idx5++;
            nums.push_back(k);
            count++;
        }
        return nums[n-1];
    }
};
