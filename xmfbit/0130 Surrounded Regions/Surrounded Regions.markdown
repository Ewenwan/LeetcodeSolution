# Surrounded Regions

标签： DSF

---

## 题目描述
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
```
X X X X
X O O X
X X O X
X O X X
```
After running your function, the board should be:
```
X X X X
X X X X
X X X X
X O X X
```

## 思路解析
这道题和 [Number of Islands](https://leetcode.com/problems/number-of-islands/) 一题相似，所以找到了这个题目练习。

和上个问题的区别在于，这里需要排除直接和边缘连通的`'O'`的区域。我的解决方案是遍历四个边缘行列，如果找到了`'O'`，那么进行DFS，将连通部分标记出来。当处理完四个边之后，所有的延伸到边的全`O`区域已经都被标记了，再遍历整个二维数组，将未被标记的位置元素置为`'X'`。

不过在实际编程的时候，使用递归DFS的时候，报告 Runtime Error。当时估计是递归层数过多，栈崩掉了，所以转而使用迭代的方法，用栈来模拟递归。通过了。

不过时间用了 36ms， 并不是很令人满意，可能需要参考讨论区再修改。

## 代码

```
class Solution {
private:
	int M;
	int N;
	inline bool verify(int row, int col, const vector<vector<bool>>& marker, const vector<vector<char>>& board) {
		return !(row < 0 || row >= M || col < 0 || col >= N || marker[row][col] || board[row][col] == 'X');
	}
	void dfs(int row, int col, const vector<vector<char>>& board, vector<vector<bool>>& marker){
		if(!verify(row, col, marker, board))    return;
		stack<int> rows;
		stack<int> cols;
		rows.push(row);
		cols.push(col);
		while(!rows.empty()) {
			row = rows.top();
			col = cols.top();
			rows.pop();
			cols.pop();
			marker[row][col] = true;
			if(verify(row + 1, col, marker, board)) {
				rows.push(row + 1);   cols.push(col);
			}
			if(verify(row - 1, col, marker, board)) {
				rows.push(row - 1);   cols.push(col);
			}
			if(verify(row, col + 1, marker, board)) {
				rows.push(row);   cols.push(col + 1);
			}
			if(verify(row, col - 1, marker, board)) {
				rows.push(row);   cols.push(col - 1);
			}
		}
	}
public:
	void solve(vector<vector<char>>& board) {
		if(board.size() == 0) return;
		M = board.size();
		N = board[0].size();
		if(M == 1 || N == 1)    return;

        vector<vector<bool>> marker(M, vector<bool>(N, false));
		
		for(int i = 0; i < N; ++i){
			dfs(0, i, board, marker);
			dfs(M - 1, i, board, marker);
		}
		for(int i = 0; i < M; ++i) {
			dfs(i, 0, board, marker);
			dfs(i, N - 1, board, marker);
		}
		for(int i = 0; i < M; ++i) {
			for(int j = 0; j < N; ++j) {
				if(!marker[i][j])
					board[i][j] = 'X';
			}
		}
	}
};
```




