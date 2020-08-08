class Solution {
public:
    /**
     * @param m: An integer
     * @param record: An integer array
     * @return: the smallest total number of the messages, if does not exist, return -1
     */
    int minimumMessages(int m, vector<int> &record) 
    {
        auto arr = record;
        for (int i=2; i<record.size(); i++)
        {
            int sum = 0;
            for (int j=i-2; j<=i; j++)
            {
                if (arr[j]!=-1)
                    sum+=arr[j];
                else
                    arr[j]=0;
            }           
            
            if (sum<m)
            {
                int diff = m - sum;
                if (record[i]==-1)
                    arr[i] += diff;
                else if (record[i-1]==-1)
                    arr[i-1] += diff;
                else if (record[i-2]==-1)
                    arr[i-2] += diff;
                else
                    return -1;
            }
        }
        
        int ret = 0;
        for (int i=0; i<record.size(); i++)
            ret+=arr[i];
        return ret;
    }
};
