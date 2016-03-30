# Combination Sum

标签： backtracking

---
## 题目描述
Given a set of candidate numbers `(C)` and a target number `(T)`, find all unique combinations in `C` where the candidate numbers sums to `T`.

The same repeated number may be chosen from `C` unlimited number of times.

Note:

 - All numbers (including target) will be positive integers.
 - Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 - The solution set must not contain duplicate combinations.

For example, given candidate set `2,3,6,7` and target `7`,
A solution set is:
```
[7]
[2, 2, 3]
```
## 思路分析

这种搜索问题的最朴素解法就是暴力搜索，而加入剪枝之后就能快速排除掉不可能的解决方案。

由于本题要求输出结果按升序排列，所以要先对原始数组进行排序（即使没有这一要求，很多时候，排序往往能够简化问题）。

在搜索解的过程当中，注意当target减去当前已经累加起来的值的差已经小于数组中最小元素的时候，在该分支上的搜索已经失败了，需要及时退出。

同时为了防止重复，比如上面例子中的`[2, 2, 3]`解和`[3, 2, 2]`解，可以保存当前解中最末尾元素在`candidates`中的索引，搜寻当前解的下一个分量的时候，直接从该索引开始，就可以保证最终解中的元素是单调增的，从而避免了`[3, 2, 2]`这种情况出现。

## 代码
```
class Solution {
    void bt(vector<vector<int>>& res, vector<int>& path, int target, int idx, const vector<int>& candidates) {
        if(target == 0)   res.push_back(path);
        else {
            for(int i = idx; i < candidates.size() && target >= candidates[i]; ++i) {
                path.push_back(candidates[i]);
                bt(res, path, target - candidates[i], i, candidates);
                path.pop_back();   // 不要忘记backtracking哦。。。
            }
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        bt(res, path, target, 0, candidates);
        return res;
    }
};
```



