#### Description
有一个二维数组，数组中元素只有 0 和 1。
你最多能将 1 个 0 变成 1，请求出由 1 组成的最大的连通块面积。
如果在二维数组中有两个 1 上下或左右相邻，可以视作它们是连通的。

#### 题解：
LeetCode 827. Making A Large Island

用DFS或者BFS预处理，将属于同一个联通分量的格子都同一标记block number.

建立hash表 block number -> number of connected elements
```
0 1 0 0 0 
1 1 1 0 0
0 0 0 1 1
1 1 0 0 0 
```
=>
```
0 2 0 0 0 
2 2 2 0 0
0 0 0 4 4
3 3 0 0 0 
```
遍历每一个0格子：查看它的四周相邻了几个不同的block number，累加所有的Map[block_number]，就是将这个0->1所能得到的联通面积。

最终答案是取遍历之后发现的最大联通面积。
