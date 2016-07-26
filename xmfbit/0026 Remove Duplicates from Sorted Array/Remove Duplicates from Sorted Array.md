# Remove Duplicates from Sorted Array

标签： two_pointer

---

## 题目描述
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array `nums = [1,1,2]`,

Your function should return `length = 2`, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
## 思路分析
由于是有序数组的去重，所以可以知道重复数字都是相邻的。所以我们可以使用一个指针`i`来标记`aa...a`(用a表示某个数字)的起始位置，用另一个指针`j`去标记它的停止位置。那么直接令`nums[i+1] = nums[j+1]`即可。
## 代码
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        if(n < 2)   return n;
        while(i < n) {
            while(j < n && nums[j] == nums[i]) ++j;
            if(j == n)  return i+1;
            nums[++i] = nums[j++];
        }
        return i+1;
    }
};
```




