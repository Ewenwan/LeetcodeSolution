# N-Queens

标签： back_tracking

---

## 题目描述
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
```
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
```
## 思路分析
思路分析可以见 [N-Queens II](../0052 N-Queens II/0052 N-Queens II.md)。这里只需要加上一个辅助函数，用来将`px`转换为字符组成的棋盘即可。
## 代码
```
class Solution {
    int n;
    vector<string> getBoard(const vector<int>& px) {
        vector<string> board(n, string(n, '.'));
        for(int i = 0; i < n; ++i) {
            board[i][px[i]] = 'Q';
        }
        return board;
    }
    void bt(vector<vector<string>>& res, vector<bool>& mask, vector<int>& px) {
        if(px.size() == n) {
            res.push_back(getBoard(px));
            return;
        }
        for(int j = 0; j < n; ++j) {
            if(mask[j]) continue;
            int k = 0;
            for(; k < px.size(); ++k) {
                if(px[k] - j == k - px.size() || px[k] - j == px.size() - k) break;
            }
            if(k < px.size())   continue;
            mask[j] = true;
            px.push_back(j);
            bt(res, mask, px);
            px.pop_back();
            mask[j] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<string>> res;
        vector<bool> mask(n, false);
        vector<int> px;
        bt(res, mask, px);
        return res;
    }
};
```




