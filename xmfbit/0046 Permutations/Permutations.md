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

## 思路2
上面的代码中，我们使用了一个`vector<bool>`数组来表明某个位置的元素已经被用过，防止在其子过程中再次被用到。这样做会使得每次递归子过程都会发生一次对`mask`的拷贝操作，对时间和空间都是浪费。我们可以采用这样的思路：不设置`mask`，而是将每次用到的元素hijiaohu交换到数组的末尾，同时使用一个变量标记递归的深度，得到下面的代码：
```
class Solution {
    void bt(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int end) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < end; ++i) {
            path.push_back(nums[i]);
            swap(nums[i], nums[end-1]);  // 我们将该次使用到的元素放到数组的当前末尾
            bt(res, path, nums, end - 1); // 将end-1，使得下次就不会用到末尾元素了
            path.pop_back();
            swap(nums[i], nums[end-1]);  // 等这个分支被递归完了，我们将它交换回来
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n == 0)  return res;
        vector<int> path;
        bt(res, path, nums, n);
        return res;
    }
};
```

## 思路3
上面我们的解法仍有提升。由于我们设置了`path`变量来存储可能的解（相当于是解空间里面的那棵树从根节点到叶子节点的一条路径），相当于每次的解都会复制一遍。实际上对于回溯完全可以就地解决。使用`nums`，活用上面提到的`swap`操作。将
```
Permutation(S) = si + Permutation(S-si)
// 其中 i = 0的特例
Permutation(S) = s0 + Permutation(S-s0)
```
我们只要重复的交换首元素和其他位置的元素就可以了(让大家轮流当`s0`)。得到如下的解答：
```
class Solution {
    void bt(vector<vector<int>>& res, vector<int>& nums, int start) {
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int k = start; k < nums.size(); ++k) {
            swap(nums[k], nums[start]);
            bt(res, nums, start + 1);
            swap(nums[k], nums[start]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        bt(res, nums, 0);
        return res;
    }
};
```

这样，我们的时间也从16ms提高到了12ms，排位从后10%提高到了前25%。