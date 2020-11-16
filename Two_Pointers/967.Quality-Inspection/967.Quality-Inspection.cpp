class Solution {
public:
    /**
     * @param a: the excellent scores
     * @param b: the good scores
     * @param p: p% stands the line of valuable products.
     * @return: return the possible max number products to buy.
     */
    int qualityInspection(vector<int> &a, vector<int> &b, int p) 
    {
        int n = a.size();
        vector<vector<int>>arr;
        for (int i=0; i<n; i++)
            arr.push_back({a[i],i,1});
        for (int i=0; i<n; i++)
            arr.push_back({b[i],i,0});
        sort(arr.begin(), arr.end());
        
        int ret = 0;   
        vector<int>visited(n);   
        int count = 0;
        int i = 2*n-1;
        for (int j=2*n-1; j>=0; j--)
        {
            while (i>=0 && arr[i][0] >= arr[j][0]*p/100.0)
            {
                if (visited[arr[i][1]]==0)
                {
                    visited[arr[i][1]] = 1;
                    count++;
                }
                i--;
            }
            ret = max(ret, count);
                    
            if (arr[j][2]==0 || b[arr[j][1]] < arr[j][0]*p/100.0)
            {
                visited[arr[j][1]]--;
                count--;
            }
            
            if (arr[j][2]==0) break;
            if (i<0) break;
        }
    
        return ret;
    }
};
