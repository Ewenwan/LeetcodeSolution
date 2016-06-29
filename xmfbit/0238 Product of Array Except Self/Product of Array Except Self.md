# Product of Array Except Self

标签： math

---

## 题目描述

Given an array of n integers where n > 1, `nums`, return an array output such that output[i] is equal to the product of all the elements of nums except `nums[i]`.

Solve it without division and in O(n).

For example, given `[1,2,3,4]`, return `[24,12,8,6]`. 

## 思路分析
这道问题的新意在于不允许使用除法运算，实际上稍作变形即可发现规律：

<a href="http://www.codecogs.com/eqnedit.php?latex=r_i=\prod_{j\neq&space;i}a_j=\prod_{j=0}^{i-1}a_j\prod_{j=i&plus;1}^{m-1}a_j" target="_blank"><img src="http://latex.codecogs.com/gif.latex?r_i=\prod_{j\neq&space;i}a_j=\prod_{j=0}^{i-1}a_j\prod_{j=i&plus;1}^{m-1}a_j" title="r_i=\prod_{j\neq i}a_j=\prod_{j=0}^{i-1}a_j\prod_{j=i+1}^{m-1}a_j" /></a>

所以我们先扫描一轮，计算第一项，再从后向前扫描，计算第二项。所以本题是一个数学脑筋急转弯。。。

## 代码
```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for(int i = 1; i < res.size(); ++i) {
            res[i] = res[i-1] * nums[i-1];
        }
        int prod = nums[nums.size()-1];
        for(int i = res.size()-2; i >= 0; --i) {
            res[i] *= prod;
            prod *= nums[i];
        }
        return res;
    }
};
```




