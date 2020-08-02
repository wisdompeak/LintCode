class Solution {
public:
    /**
     * @param stops: An array represents where each car stops.
     * @param k: The number of cars should be covered.
     * @return: return the minimum length of the shed that meets the requirements.
     */
    int calculate(vector<int> &stops, int k) {
        sort(stops.begin(), stops.end());
        
        // corner case
        if (stops.size()==k)
            return stops.back()-stops[0]+1;
            
        int ret = 0;
        
        for (int i=k; i<stops.size(); i++)
        {
            int d = stops[i]-stops[i-k];
            ret = max(ret, d);
        }
        return ret;
    }
};
