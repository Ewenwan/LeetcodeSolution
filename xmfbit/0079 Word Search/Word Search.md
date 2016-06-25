# Word Search

标签： 递归

---

## 题目描述

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =
```
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
```
word = `"ABCCED"`, -> returns `true`,
word = `"SEE"`, -> returns `true`,
word = `"ABCB"`, -> returns `false`.
## 思路分析

这道题可以使用深度优先搜索。思路并不是很难。

```
bfs(board, word, n, mask, pos): // 其中mask用来标记这个位置是否已经访问过了
    if n == word.size()   return true   // 说明全词已经找到了
    if pos is beyond [rows, cols]  return false   // 已经找到了给定区域以外，说明此路不通
    if board[pos] != word[n] || mask[pos] == true    return false
    // 说明这个位置要么不是要找的字符，要么已经被访问过，说明不通
    // --------- 以上部分即为递归基
    // 这种问题一定要把递归基选好，做到不重不漏，否则可能就会导致无穷递归或是数组越界等runtime error
    // 下面就是递归了
    mask[pos] = true   // 标记这个点已经被访问过了
    for 上下左右四个邻域
        next_pos = 新的邻域位置
        if bfs(board, word, n+1, mask, next_pos) == true  //说明此路已通
            return true
    return false // 四个邻域均不满足，说明此路不通
```
可以看到，上面的代码中为了标记一个点是否被访问过（题目有要求，每个位置的字符最多使用一次，为了防止重复使用同一位置的字符），使用了一个`mask`变量用来标记当前路径节点上哪些点被访问过了。结果代码出现了TLE。这段代码可见代码段1.

确认方法无误后，想到是否可以不用`mask`变量？之所以会访问之前的节点，是因为这个节点的值会再次被用到，那我在访问过这个节点后，将它的值人为改为一个不可能被用到的值不就行了？要注意的是，当发现此路不同要回溯的时候，需要将这个点的原始值恢复。于是就有了代码段2，是可以AC的。

## 代码

### 代码1，使用mask标记，TLE
```
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution {
    struct XY {
        int x = 0;
        int y = 0;
        XY(int x, int y): x(x), y(y) {}
    };
    bool bt(const vector<vector<char>>& board, const string& word, int n, const XY& xy, vector<vector<bool>> mask) {
        if(n == word.size())    return true;
        if(xy.x < 0 || xy.x >= board[0].size() || xy.y < 0 || xy.y >= board.size()) return false;
        if(mask[xy.y][xy.x])    return false;
        mask[xy.y][xy.x] = true;
        if(board[xy.y][xy.x] != word[n])    return false;
        for(int i = 0; i < 4; ++i) {
            XY next_pos(xy.x + dx[i], xy.y + dy[i]);
            if(bt(board, word, n + 1, next_pos, mask))    return true;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())    return true;
        int rows = board.size();
        if(rows == 0)   return false;
        int cols = board[0].size();
        vector<vector<bool>> mask(rows, vector<bool>(cols, false));
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(bt(board, word, 0, XY(c, r), mask)) return true;
            }
        }
        return false;
    }
};
```

### 代码2，修改已经访问的节点的值，AC
```
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution {
    struct XY {
        int x = 0;
        int y = 0;
        XY(int x, int y): x(x), y(y) {}
    };
    bool bt(vector<vector<char>>& board, const string& word, int n, const XY& xy) {
        if(n == word.size())    return true;
        if(xy.x < 0 || xy.x >= board[0].size() || xy.y < 0 || xy.y >= board.size()) return false;
        if(board[xy.y][xy.x] != word[n])    return false;
        board[xy.y][xy.x] = ' ';
        for(int i = 0; i < 4; ++i) {
            XY next_pos(xy.x + dx[i], xy.y + dy[i]);
            if(bt(board, word, n + 1, next_pos))    return true;
        }
        board[xy.y][xy.x] = word[n];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())    return true;
        int rows = board.size();
        if(rows == 0)   return false;
        int cols = board[0].size();
        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(bt(board, word, 0, XY(c, r))) return true;
            }
        }
        return false;
    }
};
```
