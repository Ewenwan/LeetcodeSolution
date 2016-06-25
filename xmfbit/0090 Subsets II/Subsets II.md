# Subsets II

标签： 递归

---

## 题目描述

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = `[1,2,2]`, a solution is:
```
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```
## 思路分析
这个问题和 [Subsets](https://leetcode.com/problems/subsets/) 的区别在于所给元素是有重复的。

手写`[0, 0, 1, 1]`可以发现一些规律：
```
[]             n = 0

[], [0]        n = 1， 此时元素与上个位置不重复，我们把上一步得到的结果中的每个set再append当前元素就好了

[], [0]  [0, 0]   n = 2，此时元素和上个位置的0是重复的。注意我们是从 n = 1时候的第2个元素才append的（即[0, 0]是由[0] append 来的， n=1时候的[] 被无视了）

[], [0], [0, 0], [1], [0, 1], [0, 0, 1]  n = 3，此时元素和上个位置的0不同，所以我们把上一步得到的结果中的每个set再append当前元素就行了
```

所以，在当前元素和上个元素重复的时候，我们不能将上步结果中的所有set拿来都append当前值了，我们需要跳过开头的若干元素。具体跳过的个数就是上一步中从它的上一步中继承来的那些set。所以我们有必要使用一个变量（下面代码中的`prev_size`）来记录当前步的父亲步从当前步的爷爷步继承的set数量。

## 代码
```
class Solution {
    void append_solution(vector<vector<int>>& res, int start, int end, int val) {
        for(int i = start; i < end; ++i) {
            auto v = res[i];
            v.push_back(val);
            res.push_back(v);
        }
    }
    void bt(vector<vector<int>>& res, const vector<int>& nums, int cur_size, int& prev_size) {
        if(cur_size == 0) {
            res.push_back(vector<int>());
            return;
        }
        bt(res, nums, cur_size - 1, prev_size);

        if(cur_size == 1 || nums[cur_size-1] != nums[cur_size-2]) {
            prev_size = res.size();
            append_solution(res, 0, prev_size, nums[cur_size-1]);
        } else {
            int res_size = res.size();
            append_solution(res, prev_size, res_size, nums[cur_size-1]);
            prev_size = res_size;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int prev_size = 0;
        bt(res, nums, nums.size(), prev_size);
        return res;
    }
};
```
