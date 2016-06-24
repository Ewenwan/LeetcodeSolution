# Gray Code

标签： 递归

---

## 题目描述
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given `n = 2`, return `[0,1,3,2]`. Its gray code sequence is:
```
00 - 0
01 - 1
11 - 3
10 - 2
```

## 思路分析
通过递归思路很好解决。关键是找到规律。我手写了`n=3`情况下的格雷码的生成。
```
0 0 0
0 0 1
0 1 1
0 1 0
--------- 注意到前2^(n-1)个格雷码都是n-1情况下的格雷码前面加个0得到
1 1 0     
1 1 1
1 0 1
1 0 0
-------  注意到后面的这一半是将前面一半的最高位0改为1，反向遍历得到的～
110 和 010, 111 和 011 等。
```
只要看出了上面的规律，那么写出代码也就不难了～
## 代码
```
class Solution {
    void bt(vector<int>& res, int n) {
        if(n == 1) {
            res.push_back(0);
            res.push_back(1);
            return;
        }
        bt(res, n - 1);
        int size = res.size();
        for(int i = size - 1; i >= 0; --i) {
            int bits = res[i];
            bits |= (1U << n-1);
            res.push_back(bits);
        }
    }
public:
    vector<int> grayCode(int n) {
        if(n == 0)  return vector<int>{0};
        vector<int> res;
        bt(res, n);
        return res;
    }
};
```




