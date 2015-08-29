# Pascal's Triangle

标签： math

---

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
```
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

## 思路解析

这个问题关于[Pascal三角](https://en.wikipedia.org/wiki/Pascal's_triangle)(或杨辉三角)
可以用组合数的递推公式来做，其实就是一个数学问题。

## 代码
```
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> pascal;
        for(int i = 0; i < numRows; ++i)
        {
            pascal.push_back(vector<int>(i+1,1));
            for(int j = 1; j < i; ++j)
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
        return pascal;
    }
};
```