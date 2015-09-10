# Missing Number

标签：bit_operation 

---
## 题目描述
Given an array containing n distinct numbers taken from `0, 1, 2, ..., n`, find the one that is missing from the array.

For example,
Given `nums = [0, 1, 3]` return `2`.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? 

## 思路解析
这道题如果有这个知识点的话就很简单：两个相同的数异或的结果是0.
以前是遇到过这样一个问题：在从1到n的一堆数里面，有且只有一个数个数是1，其他数都有两个。找出这个数。其实和这个问题是一样的。

## 代码
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int bit = 0;
        for(int i = 1; i <= n; ++i)   // 除了要找的那个数，别的数就都有两个了
            bit ^= i;
        for(int i = 0; i < n; ++i)
            bit ^= nums[i];
        return bit;
    }
};
```



