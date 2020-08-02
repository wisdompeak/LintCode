#include <bits/stdc++.h>

class Solution {
    int label;
    unordered_map<int,int>Map;
public:
    /**
     * return the max area after operation at most once.
     * @param matrix int整型vector<vector<>> the matrix for calculation.
     * @return int整型
     */
    int maxArea(vector<vector<int> >& grid) 
    {
        int M=grid.size();
        int N=grid[0].size();
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
        
        label=1;
        
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
            {
                if (grid[i][j]==0) continue;
                if (visited[i][j]!=0) continue;                
                DFS(i,j,grid,visited);
                label++;
            }
        
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        int result = 0;
        
        int flag=0;
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
            {
                if (grid[i][j]!=0) continue;
                
                flag = 1;
                
                unordered_set<int>Set;
                for (int k=0; k<4; k++)
                {
                    int x = i+dir[k].first;
                    int y = j+dir[k].second;
                    if (x<0||x>=M||y<0||y>=N)
                        continue;
                    if (grid[x][y]==0)
                        continue;
                    Set.insert(visited[x][y]);                    
                }
                
                int temp = 0;
                for (auto a:Set)
                    temp+=Map[a];
                
                result = max(result,temp+1);                
            }
        
        if (flag==0)
            return M*N;
        else
            return result;
    }
    
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        int M=grid.size();
        int N=grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        int count=0;
        
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            count++;
            visited[x][y]=label;
            q.pop();
            
            for (int k=0; k<4; k++)
            {
                int xx=x+dir[k].first;
                int yy=y+dir[k].second;
                
                if (xx<0||xx>=M||yy<0||yy>=N)
                    continue;
                if (grid[xx][yy]==0)
                    continue;       
                if (visited[xx][yy]!=0)
                    continue;
                q.push({xx,yy});
                visited[xx][yy]=label;
            }
        }
        
        Map[label]=count;        
        
    }
};
