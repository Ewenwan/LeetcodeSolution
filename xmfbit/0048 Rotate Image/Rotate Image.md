# Rotate Image

标签：math

---

## 题目描述
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
## 思路分析
这个问题要求顺时针旋转一个二维的矩阵，可以看做是找规律的问题。首先，我尝试了naive的方法，直接开辟n^2的新的数组，然后可以发现，src的第i行变成了dst的n-i列。也就有了下面的`rotate_naive`这个解法。

如果要求就地反转，就需要找到其中更多的规律。画图做几个例子不难发现，旋转的时候，数字的交换只会在同一个环上发生（可以将矩阵想象为大城市的环路，矩阵中心是市中心）。而且，只会是4个数字在一起交换。所以可以记录这四个数字的位置，交换即可。
## 代码
```
class Solution {
    struct Point {
        int x, y;
        Point(int x = 0, int y = 0):x(x), y(y) {}
        Point& up() {y -= 1; return *this;}
        Point& down() {y += 1; return *this;}
        Point& left() {x -= 1; return *this;}
        Point& right() {x += 1; return *this;}
    };
private:
    void rotate_naive(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp = matrix;
        int rows = matrix.size();
        for(int r = 0; r < rows; ++r) {
            // for each row in the original matrix
            // the new position is the (rows-1-r)th column in the result
            int dst_col = rows - 1 - r;
            for(int rr = 0; rr < rows; ++rr) {
                matrix[rr][dst_col] = tmp[r][rr];
            }
        }
    }
    
    void rotate_inplace(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<Point> pos{Point(0, 0), Point(n-1, 0), Point(n-1, n-1), Point(0, n-1)};
        for(int i = 0; i < n/2; ++i) {
            int len = n - 2*i;   // the length of ith ring
            vector<Point> ori = pos;
            for(int k = 0; k < len-1; ++k) {
                int tmp = matrix[pos[3].y][pos[3].x];
                for(int j = 3; j > 0; --j) {
                    matrix[pos[j].y][pos[j].x] = matrix[pos[j-1].y][pos[j-1].x];
                }
                matrix[pos[0].y][pos[0].x] = tmp;
                pos[0].right();
                pos[1].down();
                pos[2].left();
                pos[3].up();
            }
            pos = ori;
            pos[0].right().down();
            pos[1].left().down();
            pos[2].left().up();
            pos[3].right().up();
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty())  return;
        rotate_inplace(matrix);
    }
};
```




