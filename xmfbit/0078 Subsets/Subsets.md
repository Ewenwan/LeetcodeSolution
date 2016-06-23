# Subsets

标签： 递归

---

## 题目描述
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = `[1,2,3]`, a solution is:
```
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```
## 思路分析
使用递归的思路解决，关键是找到递推公式：
$$
Solution(S_n) = Solution(S_{n-1}) + \sum_{s \in S_{n-1}}(s \cup n)  
$$

上面的式子中，用加法表示并。

## 代码
```
class Solution {
    void solve(vector<vector<int>>& res, const vector<int>& nums, int n) {
        if(n == 0) {
            res.push_back(vector<int>());
            return;
        }
        solve(res, nums, n-1);
        int size = res.size();
        for(int i = 0; i < size; ++i) {
            vector<int> tmp = res[i];
            tmp.push_back(nums[n-1]);
            res.push_back(tmp);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res, nums, nums.size());
        return res;
    }
};
```



