# Factorial Trailing Zeroes

标签： math

---

## 题目描述
Given an integer `n`, return the number of trailing zeroes in `n!`.

Note: Your solution should be in logarithmic time complexity.

## 思路
求`n!`的末尾0的个数， 比较容易想到的是将属于这个范围的整数`m`分解质因数
$$m = 2^{k_1}3^{k_2}5^{k_3}...$$
则因子`m`贡献的`0`的个数为$$\min(k_1,k_3)$$
最后相加就可以了。然而这样做肯定不能满足对数时间复杂度的要求。

可以想到，其实质因数2的数量要比5少，也就是说，其实$\min(k_1,k_3)$是一定等于$k_3$的。所以我们只要计算`m`的5质因数的个数就可以了。

```
res = 0
for m = 5:n
    res = f(m)   // f(m)是m中5质因数的个数，可以在对数时间内完成
end
```
然而上面的解法仍然不是最优的。因为仍然要遍历序列，分别计算每个数的质因数5的个数。继续深入，可以想到，在自然数序列中，是每隔5才会出现一个5的倍数，所以，我们只要用`n/5`就能够知道`n`之前有多少个数有5这个质因数。用`n/25`就可以知道`n`前面有多少个数有25这个因数（也就是说有两个5）。所以这个问题的解是
$$\lfloor n/5\rfloor+\lfloor n/25\rfloor+...$$

```
res = 0;
num = 5;
while(num <= n)
    res += n / num;
    num *= 5;
end
```

这样做的确满足了题目要求，但还有一点问题，那就是`num`是5的幂次，会是一个比较大的数字，我们不妨逆向考虑， 每次将`n/5`，得到最终的解法

## 代码
```
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n) {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};
```




