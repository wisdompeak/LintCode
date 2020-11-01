class Solution {
public:
    /**
     * @param a: first sequence
     * @param b: second sequence
     * @return: return ans
     */
    vector<vector<int>> Intersection(vector<vector<int>> &a, vector<vector<int>> &b) 
    {
        int i = 0, j = 0;
        vector<vector<int>>rets;
        while (i<a.size() && j<b.size())
        {
            if (a[i][1] < b[j][0])
            {
                i++;
            }
            else if (b[j][1] < a[i][0])
            {
                j++;
            }
            else
            {
                rets.push_back({i,j});
                if (a[i][1]<=b[j][1])
                    i++;
                else
                    j++;
            }
        }
        return rets;
    }
};  
