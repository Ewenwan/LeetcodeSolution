# Move Zeroes
标签： two_pointer

---
## 题目描述

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = `[0, 1, 0, 3, 12]`, after calling your function, nums should be `[1, 3, 12, 0, 0]`.

Note:

- You must do this in-place without making a copy of the array.
- Minimize the total number of operations.

## 思路解析
这道题要求在保证非零元素顺序的前提下，将所有的0移动到数组的最右端。由于这里只是针对0元素，所以我们可以遍历一遍数组，将非零元素依次排列，最后剩多少个空位给0就好了。

## 代码
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto itend = nums.end(), its = nums.begin();   // its 是慢指针
        for(auto itf = its; itf != itend; ++itf)    // itf是快指针，负责遍历
            if(*itf != 0)   *its++ = *itf;
        while(its != itend)   // 用0补位
            *its++ = 0;
    }
};
```



