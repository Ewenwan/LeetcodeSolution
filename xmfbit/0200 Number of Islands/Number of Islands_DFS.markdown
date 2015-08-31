# Number of Islands_DFS

标签： DFS

---
##　题目描述
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
```
11110
11010
11000
00000
```
Answer: `1`

Example 2:
```
11000
11000
00100
00011
```
Answer: `3`
## 思路解析
这道题目给出的tag是DFS， BFS和 [并查集](http://www.algorithmist.com/index.php/Union_Find)。这里采用的方法是DFS。

DFS和BFS都是一种回溯方法，分别可以用栈和队列来实现非递归解法。这里仍然使用递归解法。

思路是这样的：
```
islands = 0
while 还有标记为‘1’的而且没有被访问过的元素:
    从这个元素为起始点， 进行DFS
    islands += 1   // 因为这意味着一个连通的1区域已经遍历完，即发现了一个小岛
```

DFS 的思路如下
```
DFS(node):
    if node == '0' || node已经被访问过:
        return        // 该处是海水，没有陆地了，返回
    // 该处是一处新路
    标记已经被访问过
    dfs(4 neighbours of node)
```
## 代码
思路写出来，实际编程还是有几处细节。
  
- 处理节点是否已经被访问过了，开始的时候我是用了一个数组来专门存储每个节点的访问状态。看到评论区的一个代码，是把访问过的grid节点处的值置为了 `'0'`。这样节省了空间。
  
-  我在实现的时候，为了处理边界，给grid加了一个框。实际比较，代码运行时间没有显著差别。

```
class Solution
{
private:
    int M;
    int N;
	void dfs(int curRow, int curCol, vector<vector<char>>& grid)
	{
		if(grid[curRow][curCol] == '0')
			return;
		grid[curRow][curCol] = '0';
		dfs(curRow - 1, curCol, grid);
		dfs(curRow + 1, curCol, grid);
		dfs(curRow, curCol - 1, grid);
		dfs(curRow, curCol + 1, grid);
	}
public:
	int numIslands(vector<vector<char>>& grid)
	{
		M = grid.size();
		if(M == 0)
			return 0;
		N = grid[0].size();
		int markernum = 0;
		vector<vector<char>> borderGrid(M+2, vector<char>(N+2, '0'));
		for(int i = 1; i <= M; ++i)
		    for(int j = 1; j <= N; ++j)
		        if(grid[i-1][j-1] == '1')
		            borderGrid[i][j] = '1';
		for(int i = 1; i <= M; ++i)
		    for(int j = 1; j <= N; ++j)
		        if(borderGrid[i][j] == '1')
		        {
			        dfs(i, j, borderGrid);
			        ++markernum;
		        }
		return markernum;
	}
};
```
开始的代码，有一个`marker`数组来标记是否被访问过。感觉比较丑。。。
```
class Solution
{
private:
    int M;
    int N;
	void dfs(int curRow, int curCol, const vector<vector<char>>& grid, vector<vector<bool>>& marker)
	{
		if(curRow < 0 || curRow >= M || curCol < 0 || curCol >= N || grid[curRow][curCol] == '0' || marker[curRow][curCol])
			return;
		marker[curRow][curCol] = true;
		dfs(curRow - 1, curCol, grid, marker);
		dfs(curRow + 1, curCol, grid, marker);
		dfs(curRow, curCol - 1, grid, marker);
		dfs(curRow, curCol + 1, grid, marker);
	}
public:
	int numIslands(vector<vector<char>>& grid)
	{
		M = grid.size();
		if(M == 0)
			return 0;
		N = grid[0].size();
		int markernum = 0;
		vector<vector<bool>> marker(M, vector<bool>(N, false));
		for(int row = 0; row < M; ++row)
		    for(int col = 0; col < N; ++col)
		        if(!marker[row][col] && grid[row][col] == '1')
		        {
			        dfs(row, col, grid, marker);
			        ++markernum;
		        }
		return markernum;
	}
};
```



