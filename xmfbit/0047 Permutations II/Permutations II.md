# Permutations II

标签：back_tracking 

---

## 题目描述

## 思路分析
这道题和0046是相似的，只不过出现了重复的元素。
刚开始的时候用了很naive的方法，见解法1.使用了一个`set`来去除重复结果，提交结果当然是TLE。。。

在看过讨论区的解答后，进行修改，同时也改进了自己的0046题的解法。应该多看讨论区啊！

为了解决重复元素的问题，首先，我们对输入的`nums`进行排序，这样相同元素会处在相邻位置。刚开始的时候，在`bt`函数中，我仍然使用`nums`的引用作为参数，结果发现不对，出现了重复结果。分析发现，交换元素会改变数组的有序性，所以，需要传值。见解法2.
## 代码
### 解法1
```
namespace std {
    template<>
    struct less<vector<int>> {
        typedef vector<int> value_type;
        bool operator() (const value_type& x, const value_type& y) {
            for(int i = 0; i < x.size(); ++i) {
                if(x[i] != y[i])  return (x[i] < y[i]);
            }
            return false;
        }
    };
}
class Solution {
private:
    void bt(set<vector<int>>& res, vector<int> path, const vector<int>& nums, vector<bool> mask) {
        if(path.size() == nums.size()) {
            res.insert(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(mask[i]) {
                path.push_back(nums[i]);
                mask[i] = false;
                bt(res, path, nums, mask);
                path.pop_back();
                mask[i] = true;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //vector<vector<int>> res;
        vector<int> path;
        set<vector<int>> res;
        vector<bool> mask(nums.size(), true);
        bt(res, path, nums, mask);
        vector<vector<int>> _ret;
        for(auto it = res.begin(); it != res.end(); ++it) {
            _ret.push_back(*it);
        }
        return _ret;
    }
};
```

### 解法2
```
class Solution {
private:
    void bt(vector<vector<int>>& res, vector<int> nums, int start) {
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int k = start; k < nums.size(); ++k) {
            if(k != start && nums[k] == nums[start]) continue;
            swap(nums[start], nums[k]);
            bt(res, nums, start + 1);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<vector<int>> res;
       bt(res, nums, 0);
       return res;
    }
};
```


