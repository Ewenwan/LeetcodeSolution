# 3Sum

标签： binary_search

---

## 题目描述
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

## 思路
思路还是较为简单的，先做排序，之后使用两个下标，从前向后遍历数组，二分查找两者和的相反数。
```
for i = 1:n
  for j = i+1:n
    key = -a[i] - a[j]
    binary_search(key) in a[j+1,...n]
    if find key then
      add to the solution
```
对于这个问题，需要加上一些操作排除重解。

## 代码
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        int i = 0;
        while(i < len) {
            int j = i + 1;
            int a = nums[i];
            while(j < len) {
                int b = nums[j];
                int key = -a - b;
                if(binary_search(nums.begin()+j+1, nums.end(), key)) {
                    res.push_back({a, b, key});
                }
                while(j < len && nums[j] == b) ++j;
            }
            while(i < len && nums[i] == a) ++i;
        }
        return res;
    }
};
```



