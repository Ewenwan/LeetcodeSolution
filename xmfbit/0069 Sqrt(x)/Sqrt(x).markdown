# Sqrt(x)

标签： math

---

## 问题描述
Implement `int sqrt(int x)`.

Compute and return the square root of `x`.

## 思路解析
这个问题并不复杂，本质上就是解一个非线性方程，可以使用二分法或者牛顿法，都是迭代解非线性方程的最普通的方法了。放在这里记录是因为讨论区有人给出了Wiki上关于计算某个数的平方根的链接，可以说还是很令人开眼界的。[Methods of computing square roots](https://en.wiki2.org/wiki/Methods_of_computing_square_roots).

## 代码
我用的是牛顿法。原来以为牛顿法收敛速度会快（记得是二阶收敛？），但是实际发现运行了8ms，并不算很突出。

```
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)  return 0;   // 防止一会除以0
        double a = x/2.0;
        while(true) {
            double tmp = a;
            a = a/2 + x/(2*a);  // a = a-(a*a-x)/(2*a);
            if(fabs(a-tmp) < 1)    return int(a);
        }
    }
};
```





