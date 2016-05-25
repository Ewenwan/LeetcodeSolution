# Intersection of Two Arrays II

标签： Hash

---

## 题目描述
Given two arrays, write a function to compute their intersection.

Example:
Given `nums1 = [1, 2, 2, 1]`, `nums2 = [2, 2]`, return `[2, 2]`. 
## 思路分析
这道题作为`STL`中`multiset`的练习。。。

## 代码
```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        multiset<int> s;
        for(auto v : nums1) {
            s.insert(v);
        }
        auto it = s.begin();
        for(auto v: nums2) {
            if((it = s.find(v)) != s.end()) {
                res.push_back(v);
                s.erase(it);
            }
        }
        return res;
    }
};
```



