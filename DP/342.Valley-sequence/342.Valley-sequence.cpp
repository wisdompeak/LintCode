class Solution {
public:
    /**
     * @param num: sequence
     * @return: The longest valley sequence
     */
    int valley(vector<int> &num) 
    {
        int n = num.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (num[j]>num[i])
                    left[i] = max(left[i], left[j]+1);
            }
        }
        for (int i=n-2; i>=0; i--)
        {
            for (int j=i+1; j<n; j++)
            {
                if (num[i]<num[j])
                    right[i] = max(right[i], right[j]+1);
            }
        }
        
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (num[i]==num[j])
                {
                    ret = max(ret, min(left[i], right[j])*2);
                    break;
                }
            }
        }
        return ret;
    }
};
