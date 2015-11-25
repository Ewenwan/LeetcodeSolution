# First Bad Version

标签： binarysearch

---
## 题目描述

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API. 

## 思路解析
这道题的解法并不是很难想到，其实相当于是在一个单调不减的序列中寻找第一个不小于XX数的位置。使用普通二分查找的变种就可以。

对于有序序列的普通二分查找，一般都会采用下面的方法：

```
while(lo <= hi) {
    mid = (lo+hi)/2;
    if(v[mid] > key)    hi = mid-1;
    else if(v[mid] < key)   lo = mid+1;
    else return mid;
}
return -1;    // 未找到
```

而这里由于是找到第一个不小于某数的位置，所以，我们在`v[mid]==key`的时候，仍归到第一种情况，即`hi=mid-1`，这样进一步在`[lo, mid)`区间内寻找就可以了。

然而这道题的提交却是TLE的。查看了讨论区发现，**这里需要注意的是两个int型数据相加，可能溢出！！！**所以在计算mid的时候，有必要进行强制类型转换到两个`long long`来相加。

## 代码
```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n, mid;
        while(lo <= hi) {
            mid = ((long long)lo + (long long)hi) >> 1;   // 注意这里的类型转换！
            if(isBadVersion(mid)) 
                hi = mid-1;
            else
                lo = mid+1;
        }
        return lo;
    }
};
```




