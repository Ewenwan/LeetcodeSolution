# Permutation Sequence

标签： math

---

## 题目描述
The set `[1,2,3,…,n]` contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for `n = 3`):
```
    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
```
Given `n` and `k`, return the kth permutation sequence.
#@ 思路分析

可知知道，对于某种排列形式 `a_1a_2...a_n`，那么它在整个全排列中的序号应是：
```
b_1*f(n-1)+b_2*f(n-2)+...+b_n*f(0)
```
其中`b_k`是`a_k`在序列`{1,2,...n}`中去掉`a_1,a_2,...a_(k-1)`的序号。

所以我们要做的就是已知序号，反向求解里面的系数`b_k`。

## 代码
```
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> factors(n+1, 0);  
        factors[0] = 1;
        for(int i = 1; i <= n; ++i) {
            factors[i] = factors[i-1] * i; // f(j) = j!, j = 0, ...n
        }
        --k;  // 变为从0开始开始索引
        k %= factors[n];  // 去除周期
        vector<bool> mask(n+1, false);
        for(int i = n-1; i >= 0; i--) {
            int idx = k / factors[i] + 1; 
            int cnt = 0;
            int j = 1;
            for(; j <= n; ++j) {   // 顺序寻找，当前没有被用过的第idx数
                if(!mask[j])    ++cnt;
                if(cnt == idx) break;
            }
            // j即为本轮所求数字
            res += to_string(j);
            mask[j] = true;
            k %= factors[i];
        }
        return res;
    }
};
```



