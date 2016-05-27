# Power of Four

标签（空格分隔）： 未分类

---
## 题目描述
Given an integer (signed 32 bits), write a function to check whether it is a power of `4`.

Example:
Given `num = 16`, return `true`. Given `num = 5`, return `false`.

## 思路分析
可以很容易的判断一个数是不是2的幂次`!(a&(a-1))`。我的思路是由于`x=4^a=2^(2a)`，所以可以判断指数部分是不是2的倍数。也就是下面的代码1.
然而题目肯定不是这个意思（`log`运算太费时间吧了喂）。于是看到了讨论区的一个解答，也就是代码段2。由于4的幂次后面都是有偶数个0，所以那个1的位置一定是在奇数位上。所以我们可以设置掩码，将所有奇数位置设为0，偶数位置设为1，就可以捕获那些是2的幂次却不是4的幂次的数了。很巧妙。

## 代码
```
class Solution {
    bool isPowerOfTwo(int num) {
        auto a = num - 1;
        return (num&a) == 0;
    }
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)    return false;
        if(isPowerOfTwo(num)) {
            int b = log(num)/log(2);
            return !(b % 2);
        }
        return false;
    }
};
```
```
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num&(num-1)) && !(num & 0xAAAAAAAA);
    }
};
```