class Solution {
public:
    /**
     * @param side_length: the length of a side of the lake (it's a square)
     * @param lake_grid: a 2D matrix representing the lake 0= ice, 1= snowbank, -1= hole 
     * @param albert_row: row of Albert's snowbank
     * @param albert_column: column of Albert's snowbank 
     * @param kuna_row: row of Kuna's snowbank 
     * @param kuna_column: column of Kuna's snowbank
     * @return: a bool - whether Albert can escape
     */
    bool toPerson = 0;
    bool toBoundary = 0;

    vector<vector<int>>visited;
    int m;
    int xp, yp;

    // 返回直线运动能碰到的下一个雪堆的坐标，参数k表示方向。
    // 如果不能到达雪堆（碰到了窟窿，或者到了岸边），返回空
    vector<int>FindNext(vector<vector<int> >& lake_grid, int x, int y, int k)
    {
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});

        while (x>=0 && x<m && y>=0 && y<m)
        {
            x += dir[k].first;
            y += dir[k].second;
            if (!(x>=0 && x<m && y>=0 && y<m)) { toBoundary = 1; break; }  // 出界
            if (lake_grid[x][y]==-1) return {};  // 遇到了冰窟窿
            if (lake_grid[x][y]==1) return {x,y};  // 遇到了雪堆
        }
        
        return {};
    }

    void dfs(vector<vector<int> >& lake_grid, int x0, int y0)
    {
        if (toPerson && toBoundary) return;

        for (int k=0; k<4; k++)
        {
            vector<int> next = FindNext(lake_grid, x0, y0, k); // 定位下一个雪堆

            if (next.size()==0) continue;   // 到不了雪堆
            if (visited[next[0]][next[1]]) continue;  // 下一个雪堆已经访问过

            visited[next[0]][next[1]] = 1;  
            if (next[0]==xp && next[1]==yp) toPerson = 1;  // 找到了人

            dfs(lake_grid, next[0], next[1]);
        }
    }    
    
    bool lakeEscape(int side_length, vector<vector<int> >& lake_grid, int albert_row, int albert_column, int kuna_row, int kuna_column) {
        m = side_length;
        xp = albert_row, yp = albert_column;
        visited.resize(m);
        for (int i=0; i<m; i++)
            visited[i].resize(m,0);
        visited[kuna_row][kuna_column] = 1;

        dfs(lake_grid, kuna_row, kuna_column);

        return toPerson && toBoundary;
    }
};
