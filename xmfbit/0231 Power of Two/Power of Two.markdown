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

