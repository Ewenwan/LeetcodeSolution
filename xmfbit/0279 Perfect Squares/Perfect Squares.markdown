# Perfect Squares

标签：DP

---
## 题目描述

Given a positive integer n, find the least number of perfect square numbers (for example, `1, 4, 9, 16, ...`) which sum to `n`.

For example, given `n = 12`, return 3 because `12 = 4 + 4 + 4`; given `n = 13`, return 2 because `13 = 4 + 9`. 

## 思路解析

这个问题的思路并不是很难想到，思考时从递归入手。对于一个非完全平方数·`n`，设最少需要`F(n)`个完全平方数相加。那么

`F(n) = min{F(n-1)+1, F(n-4)+1, ..., F(n-m)+1} =  min{F(n-1), F(n-4), ..., F(n-m)}+1`

其中，`m`是小于n的最大完全平方数。

如果我们认为`F(0) = 0`，那么就可以把`n`是完全平方数的情况包含进来了。只要认为`m`是不大于`n`的完全平方数即可。

这种解法的时间复杂度是`O(n*sqrt(n))`

另外，对于一个自然数能否表示为若干个自然数的平方和形式，拉格朗日已经对此进行了研究。结论是任意的自然数都可以表示为至多4个完全平方数的和。也就是说， 本题的解只能是集合`{1,2,3,4}`里面的元素。

Leetcode上有一个基于此理论的非常巧妙的解法：[4ms C++ code - Solve it mathematically](https://leetcode.com/discuss/57066/4ms-c-code-solve-it-mathematically)

关于拉格朗日的相关研究可以参见wiki页面：[Lagrange's four-square theorem](https://en.wiki2.org/wiki/Lagrange's_four-square_theorem)

## 代码

```
class Solution {
public:
    int numSquares(int n) {
        int pro = 0;
        int minval = 3;
        vector<int> sol(n+1, 0);
        for(int i = 1; i <= n; ++i, minval = 3) {
            for(int j = 1; (pro = j*j) <= i; ++j)
                minval = min(minval, sol[i-pro]);
            sol[i] = minval+1;
        }
        return sol[n];
    }
};
```



