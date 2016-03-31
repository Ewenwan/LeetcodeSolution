# Permutations

标签： backtracking

---

## 题目描述
 Given a collection of distinct numbers, return all possible permutations.

For example,
`[1,2,3]` have the following permutations:
`[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]` 
## 思路分析

求取互不相同的整数序列的所有全排列。从空集出发，每次将未被访问过的节点加入到解中即可。

## 代码
```
class Solution {
    void bt(vector<vector<int>>& res, vector<int>& path, vector<bool>& mask, const vector<int>& nums, int n) {
        if(path.size() == n) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(!mask[i]) {
                path.push_back(nums[i]);
                mask[i] = true;
                bt(res, path, mask, nums, n);
                path.pop_back();
                mask[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n == 0)  return res;
        vector<bool> mask(n, false);
        vector<int> path;
        bt(res, path, mask, nums, n);
        return res;
    }
};
```


