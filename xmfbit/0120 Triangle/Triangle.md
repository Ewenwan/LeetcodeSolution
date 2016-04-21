# Triangle

标签： dp

---
## 题目描述
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```
The minimum path sum from top to bottom is `11` (i.e., `2 + 3 + 5 + 1 = 11`).

Note:
Bonus point if you are able to do this using only `O(n)` extra space, where n is the total number of rows in the triangle. 
## 思路分析
比较简单的动态规划问题，动态方程很容易写出。我们设`dp[i,j]`表示以节点`a[i,j]`为终点的路径和，那么可以得到
```
dp[i,j] = dp[i-1, j] + a[i,j], when j = 0
dp[i,j] = dp[i-1, j-1] + a[i,j], when j = col
dp[i,j] = min(dp[i-1,j-1], dp[i-1,j]) + a[i,j], else
```
粗略来看，需要O(n^2)的空间来存储表。不过观察可以发现，在更新dp的时候，新的值是由它左肩和头顶的旧值计算来的，那么如果我们从最后一个元素开始更新，就不会覆盖还未访问的数据了。

## 代码
```
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = triangle[rows-1].size();
        vector<int> dp(cols, 0);
        dp[0] = triangle[0][0];
        for(int i = 1; i < rows; ++i) {
            for(int j = i; j >= 0; --j) {
                if(j == i)  dp[j] = dp[j-1] + triangle[i][j];
                else if(j == 0) dp[j] = dp[j] + triangle[i][0];
                else dp[j] = std::min(dp[j], dp[j-1]) + triangle[i][j];
            }
        }
        return *std::min_element(dp.cbegin(), dp.cend());
    }
};
```




