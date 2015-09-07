# Find Peak Element

标签： 分治

---

## 题目描述
A peak element is an element that is greater than its neighbors.

Given an input array where `num[i] ≠ num[i+1]`, find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that `num[-1] = num[n] = -∞`.

For example, in array `[1, 2, 3, 1]`, `3` is a peak element and your function should return the index number `2`.

## 思路解析
在想这个问题的时候，可以从特殊到一般入手。
 
- 当序列是单调不减或者不增的时候，显然最大/最小的元素应该是极值点。
- 当序列只有一个peak而其他部分都是单调的时候，我们要做的就是尽快定位到**不单调的部分**，所以想到了使用**二分**来尽快地将单调部分走完。

接下来思考二分的方法能否找到peak。可以考虑循环不变式。我提出的不变式是：
**区间[low, high)之间存在peak**

这里没有写伪码，以下内容可以对照代码来看：
首先明确的一点是，按照题目的规定，认为`num[-1] = num[n] = -∞`，那么对于任何一个序列，都是存在peak的。

  - 初始时刻，`low = 0,high = size`，不变式显然是成立的。
  - 当一次迭代结束之后，按照`mid`和它的邻居的大小关系，继续取左子序列或者右子序列。这两个序列肯定仍然存在peak，现在我们需要证明的是**子序列的peak仍然是全局的peak**。如果peak在子序列的内部，这个是显然的。如果peak在端点位置，例如右序列的peak是最右端，那么可以推知右序列是单调递增的，那么原序列的这一部分仍然是单调自增的，所以右端点仍然是全局的peak。如果peak是最左端，可以推知右序列是单调递减的。那么由于当初分支的时候，选取右序列的条件就是`a[mid] < a[mid+1]`，那么就有`a[mid+1]>a[mid],a[mid+1]>a[mid+2]`，所以说仍然是全局的peak。

## 代码
```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int lo = 0, hi = size;
        
        while(lo < hi) {
            int mi = (lo+hi)>>1;
            if(mi+1 < size && nums[mi] < nums[mi+1])    lo = mi+1;
            else if(mi >= 1 && nums[mi] < nums[mi-1])   hi = mi;
            else return mi; 
        }
        return lo;
    }
};
```




