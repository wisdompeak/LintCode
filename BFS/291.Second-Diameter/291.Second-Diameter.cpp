class Solution {
public:
    vector<vector<pair<int,int>>>adj;    
    int V;
    /**
     * return the second diameter length of the tree
     * @param edge int整型vector<vector<>> edge[i][0] [1] [2]  start point,end point,value
     * @return long长整型
     */
    long long getSecondDiameter(vector<vector<int> >& edges) {
        V = edges.size()+1;
        adj.resize(V);        
        for (auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        vector<long long>dist0(V,-1);
        vector<long long>dist1(V,-1);
        vector<long long>dist2(V,-1);
        int v1 = bfs(0, dist0); 
        int v2 = bfs(v1, dist1);
        int v3 = bfs(v2, dist2);
        
        long long ret = 0;
        for (int i=0; i<V; i++)        
            if (i!=v1) ret = max(ret, dist2[i]);
        for (int i=0; i<V; i++)        
            if (i!=v2) ret = max(ret, dist1[i]);
        return ret;        
    }
    
    int bfs(int u, vector<long long>&dis) 
    {         
        queue<int> q; 
        q.push(u);       
        dis[u] = 0; 
        
        while (!q.empty()) 
        { 
            int cur = q.front();
            q.pop(); 
            
            for (auto x: adj[cur]) 
            {          
                int next = x.first;
                long long len = x.second;
                if (dis[next] == -1) 
                { 
                    q.push(next);   
                    dis[next] = dis[cur] + len; 
                } 
            } 
        } 
  
        long long maxDis = 0; 
        int nodeIdx;           
        for (int i = 0; i < V; i++) 
        { 
            if (dis[i] > maxDis) 
            { 
                maxDis = dis[i]; 
                nodeIdx = i; 
            } 
        } 
        return nodeIdx; 
    }     
    
};
