# Power of Two

标签： bit_operation

---

## 题目描述

Given an integer, write a function to determine if it is a power of two. 

##思路解析
给定一个整数，确定是否为２的幂次。首先想到的是一个整数是２的幂次，那么它一定是0B10..0的形式，也就是说是由0x01不断移位形成的。

可以通过不断向右移位直到出现一个1，然后判断1的前面是否仍有1来判断，不过这里用的是0x01不断向左移位，看是否和给定的n相同来判断的，相当于是穷举。这道题由于给定的是整形数，所以时间复杂度是固定的O(1)。通常来说，时间复杂度应该是O(n)，其中n是二进制的位数。

## 代码
```
class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        if(n <= 0)
            return false;
        else
        {
            int bits = sizeof(int) * 8;
            int base = 1;
            for(int i = 0; i < bits-1; base <<= 1,++i)
                if((n ^ base) == 0x0)
                    return true;
            return false;
        }
    }
};
```
## 更新
这道题目的时间复杂度仍有提升空间，可以做到O(1)的时间复杂度。

先来看这样一个事实：
如果一个二进制串从右往左数第一个不为0的数位为`k`，比如这个串：`XXXXX10000`，这时候`k = 4`，而这个数减1，由于借位，我们会发现从第0位开始到第k位都会变成原来的反。也就是说，使用`n &= (n-1)`就能够将第一个1右面的数位（包括第一个1那一位）全部清零。

而一个数如果是2的幂次，那么它一定是`1000...00`的形式，所以当采用一次上述操作的时候，结果必定是0。所以，就得到了O(1)的解法。

```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        return (n &= (n-1)) == 0;
    }
};
```
类似的题目可见[“Number of 1 Bits”](https://leetcode.com/problems/number-of-1-bits/)