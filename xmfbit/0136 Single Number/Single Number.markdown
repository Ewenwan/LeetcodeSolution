# Single Number

标签： bit_operation

---
## 题目描述
Given an array of integers, every element appears twice except for one. Find that single one.

##思路解析
知识点：A和自身异或，结果为0。

另外，我发现了一个收集各种位操作技巧的网页 [Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html) 

## 代码
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; ++i)
            nums[0] ^= nums[i];
        return nums[0];
    }
};
```



