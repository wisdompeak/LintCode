class Solution {
public:
    /**
     * Return the number of "universal" subarrays.
     * @param array int整型vector An given array.
     * @return int整型
     */
    int subarrays(vector<int>& array) 
    {
        vector<int>p;
        for (int i=0; i<array.size(); i++)
        {
            int j = i;
            while (j<array.size() && array[j]==array[i])
                j++;
            p.push_back(j-i);
            i = j-1;
        }

        int ret = 0;
        for (int i=0; i<p.size()-1; i++)
        {
            ret += min(p[i], p[i+1]);
        }
        return ret;
        
        // write code here
    }
};


