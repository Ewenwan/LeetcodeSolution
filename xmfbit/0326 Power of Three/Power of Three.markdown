# Power of Three

标签： math

---
## 题目描述
Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion? 

## 思路分析
这道题本身没有难度。想要判断一个整数是否是3的幂次，只要看它被3除之后的数是否能够一直被3整除即可。（也就是说n 能够表示为3^k的形式）
```
while(n)
    if (n % 3) return false;
    n /= 3;
```
而如果按照题目所说，要求不用任何循环和递归，我却没有想到，直到看了讨论区。看来还是没能深入挖掘n=3^k这个式子。

只需要找到[0, INT_MAX]之间最大的那个3的幂次N，那么如果一个数m不是3的幂次，也就是说这个数可以表示为m=2^k1*3^k2*...的形式，那么m就不会整除N！

## 代码
```
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        const int maxV = static_cast<int>(pow(3, floor(log10(0x7fffffff)/log10(3))));   // 这里也可以提前算出来
        return !(maxV%n);
    }
};
```

## 一个错误解法的记录
PS：开始的时候，我还想到了一种方法。可以将[0, INT_MAX]之间所有的3的幂次都存起来，然后判断这个数在不在其中即可。我尝试使用位操作的方法来得到这些数：

```
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int base = 1;
        int tmp = 0;
        while(base > tmp) {
            tmp = base;
            if(base == n)   return true;
            // base = base*3 = base*2+base
            base = base<<1 + base;   // 看到这里的问题了吗？ 由于<<比算术运算符优先级低，所以实际上这里是先计算了1+base ！！！
        }
        return false;
    }
};
```




