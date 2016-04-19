# Kth Largest Element in an Array

标签： heap

---
## 题目描述
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given `[3,2,1,5,6,4]` and `k = 2`, return `5`. 

## 思路分析
思路1：
直接使用最大堆，建立最大堆后执行k次`pop`操作即可。

思路2：
结合快排的思路，由于在划分的时候，下标为`k`的元素就是第`k`大的元素（`k=0`开始，且为排序结果为单调递减序列）。所以可以采用如下的方法递归解决：

```
find_k_largest(int* a, int p, int q, int k) :
    // 划分，确定pivot
    if pivot == k:
        return a[pivot]
    elif pivot < k:
        // 说明所求元素比a[pivot]小，在区间[pivot+1, q]之间
        return find_k_largest(a, i+1, q, k)
    else:
        // 说明所求元素比a[pivot]大，在区间[p, pivot-1]之间
        return find_k_largest(a, p, i-1, k)
```


## 代码
```
// 方法1， 使用最大堆，使用STL，代码简单，但空间复杂度高
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pd;
        for(auto num : nums)    pd.push(num);
        int i = 0, top;
        while(i++ < k) {
            top = pd.top();
            pd.pop();
        }
        return top;
    }
};
```

```
// 方法2，需要自己写划分方法，空间复杂度低
class Solution {
    int findKthLargest(int* a, int p, int r, int k) {
        int x = a[r];
        int i = p-1, j = p;
        while(j < r) {
            if(a[j] >= x) {
                std::swap(a[j], a[++i]);
            }
            ++j;
        }
        std::swap(a[r], a[++i]);
        if(i == k) return x;
        else if (i < k) return findKthLargest(a, i+1, r, k);
        else return findKthLargest(a, p, i-1, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(&nums[0], 0, nums.size()-1, k-1);
    }
};
```


