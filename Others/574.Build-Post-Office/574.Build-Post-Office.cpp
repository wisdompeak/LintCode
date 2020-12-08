class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>countX(n);
        for (int j=0; j<n; j++)
            for (int i=0; i<m; i++)
            {
                if (grid[i][j]==1)
                    countX[j]+=1;
            }
            
        vector<int>countY(m);
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==1)
                    countY[i]+=1;
            }
        
        vector<int>sumDist2x = helper(countX);
        vector<int>sumDist2y = helper(countY);
        
        int ret = INT_MAX;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0)
                {
                    ret = min(ret, sumDist2x[j]+sumDist2y[i]);
                }
            }
        if (ret==INT_MAX)
            return -1;
        else
            return ret;
    }
    
    vector<int>helper(vector<int>& count)
    {
        int n = count.size();
        vector<int>ret(n);
        
        int sum = 0;
        for (int i=0; i<n; i++)
            sum += i*count[i];
            
        int total = accumulate(count.begin(), count.end(), 0);
        
        int precount = count[0];
        ret[0] = sum;
        
        for (int i=1; i<n; i++)
        {
            ret[i] = ret[i-1] + precount - (total - precount);
            precount += count[i];
        }
        return ret;
    }
};
