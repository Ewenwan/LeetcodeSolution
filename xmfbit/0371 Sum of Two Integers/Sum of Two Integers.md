# Sum of Two Integers

标签： 位操作

---

## 题目描述
Calculate the sum of two integers a and b, but you are not allowed to use the operator `+` and `-`.

Example:
Given `a = 1` and `b = 2`, return `3`. 
## 思路分析
不允许使用加减运算符实现加法运算，我的第一思路就是数字电路里学到的加法器，所以下面的代码就是模拟一个硬件带进位加法器（全加器）的输入输出。
其中`addGate`中的逻辑关系是通过卡诺图化简得到的。写出真值表，得到这组关系并不复杂。

## 代码
```
class Solution {
public:
    // 模拟带进位的加法器，其中c是进位
    int addGate(int in1, int in2, int& c) {
        int out = in1 ^ in2 ^ c;
        c = in1&&in2 || in1&&c || in2&&c;
        return out;
    }
    int getSum(int a, int b) {
        int c = 0, res = 0;
        int in1, in2;
        for(int i = 0; i < 32; ++i) {  // 其实这里还是用了加法。。。
            in1 = (a >> i) & 1U;
            in2 = (b >> i) & 1U;
            int bit = addGate(in1, in2, c);
            res |= (bit << i);
        }
        return res;
    }
};
```



