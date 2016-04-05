# Combinations

标签： backtracking

---

## 题目描述

Given two integers n and k, return all possible combinations of k numbers out of `1 ... n`.

For example,
If `n = 4` and `k = 2`, a solution is:
```
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

## 思路分析

由于不允许重复（也就是说`[1,2]` 和 `[2,1]`被认为是同一个），所以在已经有了串`a1a2..aj`之后，下一步向其添加`aj+1`的时候，必须从大于`a[j]`的数里面去寻找。

## 代码
```
class Solution {
    void bt(vector<vector<int>>& res, vector<int>& path, int idx, int k, int n) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }
        for(int i = idx; i <= n; i++) {
            path.push_back(i);
            bt(res, path, idx + 1, k, n);
            idx ++;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        bt(res, path, 1, k, n);
        return res;
    }
};
```



