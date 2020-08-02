class Solution {
public:
    /**
     * @param graph: graph edge value
     * @return: return the minium length of graph
     */
    vector<int>Father; 
        
    int getMiniumValue(vector<vector<int>> &graph) 
    {
        int n = graph.size();
        Father.resize(n);
        for (int i=0; i<n; i++)
            Father[i] = i;
        
        vector<vector<int>>edges;
        vector<unordered_set<int>>bans(n);
        
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
            {
                edges.push_back({graph[i][j],i,j});
            }

        // sort the edges by length
        sort(edges.begin(), edges.end());            
        reverse(edges.begin(), edges.end());
        
        for (auto edge: edges)
        {
            int x = edge[1];
            int y = edge[2];
            
            // Both the nodes of this edge are in the same set. This is the ans.
            if (FindSet(x)==FindSet(y))
                return edge[0];
            
            // x will unite with all the opposite nodes of y
            if (bans[x].find(y)==bans[x].end())
            {
                for (auto t: bans[x]) Union(t, y);
                bans[x].insert(y);
                if (bans[x].size()==n-1) return edge[0]; // violate rule
            }
            
            // y will unite with all the opposite nodes of x
            if (bans[y].find(x)==bans[y].end())
            {
                for (auto t: bans[y]) Union(t, x);
                bans[y].insert(x);
                if (bans[y].size()==n-1) return edge[0]; // violate rule
            }
        }
        
        return 0;
        
    }

    int FindSet(int x)
    {
        if (x!=Father[x])
            Father[x]=FindSet(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x=Father[x];
        y=Father[y];
        if (x<y)
            Father[y]=x;
        else
            Father[x]=y;
    }
};
