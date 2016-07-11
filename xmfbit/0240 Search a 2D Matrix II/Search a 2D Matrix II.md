# Search a 2D Matrix II

标签： search

---

## 题目描述
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:
```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```
Given `target = 5`, return `true`.

Given `target = 20`, return `false`.
## 思路分析
这道题目以前在其他地方已经看到过了。关键点就是每次都和右上角的元素比较，如果比它小，说明待寻找的数在这一列的左面；如果比它大，说明在这一行的下面。递归地去找就行了。
## 代码
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m_row = matrix.size(), m_col = matrix[0].size();
        int row = 0, col = m_col - 1;
        while(row < m_row && col >= 0) {
            int num = matrix[row][col];
            if(num == target)   return true;
            if(num < target)    ++row;
            else --col;
        }
        return false;
    }
};
```





