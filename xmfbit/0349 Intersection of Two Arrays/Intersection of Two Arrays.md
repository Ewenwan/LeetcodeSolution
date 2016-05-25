# Intersection of Two Arrays

标签： set

---

## 题目描述
Given two arrays, write a function to compute their intersection.

Example:
Given `nums1 = [1, 2, 2, 1]`, nums2 = `[2, 2]`, return `[2]`. 
## 思路分析
`STL`中`set`的练习。。。
## 代码
```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s;
        for(auto v: nums1) {
            s.insert(v);
        }
        for(auto v: nums2) {
            auto it = s.find(v);
            if(it != s.end()) {
                s.erase(it);
                res.push_back(v);
            }
        }
        return res;
    }
};
```




