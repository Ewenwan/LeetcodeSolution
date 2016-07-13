# Spiral Matrix II

标签： math

---

## 题目描述
Given an integer `n`, generate a square matrix filled with elements from `1` to `n^2` in spiral order.

For example,
Given `n = 3`,
You should return the following matrix:
```
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```
## 思路分析
数学找规律即可。从左上角的元素开始，首先向右填充，然后向下，向左，向上；重复。所以循环这四个方向的填充过程即可。同时注意更新上下左右边界。
## 代码
```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int upbound = 0, downbound = n, leftbound = 0, rightbound = n;
        int size = n * n;
        int cnt = 0;
        int x = 0, y = 0;
        while(cnt < size) {
            while(x < rightbound && cnt < size) {
                res[y][x] = ++cnt;
                x++;
            }
            x--;
            upbound++;
            y++;
            while(y < downbound && cnt < size) {
                res[y][x] = ++cnt;
                y++;
            }
            y--;
            x--;
            rightbound--;
            while(x >= leftbound && cnt < size) {
                res[y][x] = ++cnt;
                x--;
            }
            x++;
            y--;
            downbound--;
            while(y >= upbound && cnt < size) {
                res[y][x] = ++cnt;
                y--;
            }
            y++;
            x++;
            leftbound++;
        }
        return res;
    }
};
```




