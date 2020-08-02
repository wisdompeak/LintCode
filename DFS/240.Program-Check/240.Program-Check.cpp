#include <bits/stdc++.h>

class Solution {
public:
    /**
     * return is the program may be in endless loop.
     * @param commands string字符串vector the commands of this program.
     * @return bool布尔型
     */
    vector<int>visited;
    vector<vector<int>>graph;
    
    bool check(vector<string>& commands) 
    {
        int n = commands.size();
        graph.resize(n);
        visited.resize(n,0);

        // 标记行号
        unordered_map<string,int>Map;
        for (int i=0; i<n; i++)
        {
            if (commands[i][0]=='l')
                Map[commands[i].substr(6)] = i;
        }
        
        // 构建有向图关系
        for (int i=0; i<n; i++)
        {
            if (commands[i].substr(0,5)=="goto ")
            {
                string label = commands[i].substr(5);
                graph[i].push_back(Map[label]);
            }
            else if (commands[i].size()>8 && commands[i].substr(0,8)=="gotorand")
            {
                int blank = commands[i].find(" ",9);
                string label1 = commands[i].substr(9,blank-9);
                string label2 = commands[i].substr(blank+1);
                graph[i].push_back(Map[label1]);
                graph[i].push_back(Map[label2]);
            } 
            else if (commands[i][0]!='h')
            {
                if (i+1<n) graph[i].push_back(i+1);
            }
        }
        
        // dfs判断是否有环
        return dfs(0);
    }
    
    bool dfs(int cur)
    {
        visited[cur] = 2;
        for (auto next: graph[cur])
        {
            if (visited[next]==1) continue;
            if (visited[next]==2) return true;
            if (dfs(next)==true) return true;
        }
        visited[cur] = 1;
        return false;
    }
};
