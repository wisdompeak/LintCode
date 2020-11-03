class Solution {
public:
    /**
     * @param lunch: an array that contains each lunch food's calories and value
     * @param dinner: an array that contains each dinner food's calories and value
     * @param T: the minest limit value
     * @return: return the min calories
     */
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
    int getMinCalories(vector<vector<int>> &lunch, vector<vector<int>> &dinner, int T) 
    {

        sort(lunch.begin(), lunch.end(), cmp);
        sort(dinner.begin(), dinner.end(), cmp);
        
        int j = dinner.size()-1;
        
        set<int>Set;
        int ret = INT_MAX;
        for (int i=0; i<lunch.size(); i++)
        {
            while (j>=0 && lunch[i][1]+dinner[j][1]>=T)
            {
                Set.insert(dinner[j][0]);
                j--;
            }
            if (Set.size()>0)
                ret = min(ret, lunch[i][0]+*Set.begin());
        }
        
        
        for (auto x: lunch)
        {
            if (x[1]>=T)
                ret = min(ret, x[0]);
        }
        for (auto x: dinner)
        {
            if (x[1]>=T)
                ret = min(ret, x[0]);
        }
        
        if (ret==INT_MAX)
            return -1;
        else
            return ret;
    }
};
