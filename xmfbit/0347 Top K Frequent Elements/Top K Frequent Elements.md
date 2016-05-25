# Top K Frequent Elements

标签： map

---

## 题目描述
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given `[1,1,1,2,2,3]` and `k = 2`, return `[1,2]`. 
## 思路分析
使用`map`计数，并找到前K个频次高的数即可。`map`的练习。。。
## 代码
```
class Solution {
    typedef pair<int, int> Pair;
    static bool comp(const Pair& p1, const Pair& p2) {
        return p1.second > p2.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        for(auto v: nums) {
            counter[v]++;
        }
        vector<Pair> v;
        v.reserve(counter.size());
        for(const auto& p : counter) {
            v.push_back(p);
        }
        std::partial_sort(v.begin(), v.begin() + k, v.end(), comp);
        vector<int> res;
        res.reserve(k);
        for(int i = 0; i < k; ++i) {
            res.push_back(v[i].first);
        }
        return res;
    }
};
```



