# Search for a Range

标签： binary_search

---
## 题目描述
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of `O(log n)`.

If the target is not found in the array, return `[-1, -1]`.

For example,
Given `[5, 7, 7, 8, 8, 10]` and target value `8`,
return `[3, 4]`. 
## 思路分析
使用二分查找上下边界，稍微改动二分搜索的判断条件即可。当寻找上边界时，不需要再将`lo`设为`0`，将当前位置作为左边界即可。

## 代码
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        int lower = 0, upper = 0;
        while(lo <= hi) {
            int mid = (lo+hi) >> 1;
            if(nums[mid] >= target) hi = mid-1;
            else lo = mid+1;
        }
        if(nums[lo] != target)  return vector<int>{-1, -1};
        lower = lo;
        hi = nums.size()-1;
        while(lo <= hi) {
            int mid = (lo+hi) >> 1;
            if(nums[mid] > target)  hi = mid-1;
            else lo = mid+1;
        }
        upper = hi;
        return vector<int>{lower, upper};
    }
};
```




