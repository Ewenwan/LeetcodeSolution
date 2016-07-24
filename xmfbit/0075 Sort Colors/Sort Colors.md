# Sort Colors

标签： counting_sort two_pointer

---

## 题目描述
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem. 
## 思路分析
这道问题是一道特殊的排序。因为排序之后相同的元素就会紧邻。特殊体现在我们预先知道输入数据的范围为{0, 1, 2}。所以可以很自然地想到使用counting-sort，分别对0,1,2进行计数，最后再扫一遍数组，对应填上相应数目的数字即可。见下方的代码段1.

提示中要求我们只扫描一遍数组，同时使用常数的空间。突然想到，这不就是快速排序里面三切分的划分么？我们取1为pivot element，然后将数组划分为小于1的，等于1的，大于1的三部分不就可以了？之所以能够这样做，正是利用了该数组只有三种元素的性质。

我们使用三个指针来分组。[0, lt)范围内的元素都是小于pivot的（也就是0）；[lt, i)之间的元素都是等于pivot的（也就是1）；[i, gt]之间的元素为待处理；(gt, n)之间的元素都是大于pivot的（也就是2）。i为目前要处理的元素。

分成以下三种情况：
```
if a[i] < pivot swap(a[i], a[lt]); i++, lt++;
if a[i] > pivot swap(a[i], a[gt]); gt--;
if a[i] == pivot i++;
```


## 代码

### 代码1（counting-sort）
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0, 0, 0};
        for(int color: nums) {
            ++cnt[color];
        }
        int idx = 0;
        cnt[1] += cnt[0];
        cnt[2] += cnt[1];
        while(idx < cnt[0]) {
            nums[idx++] = 0;
        }
        while(idx < cnt[1]) {
            nums[idx++] = 1;
        }
        while(idx < cnt[2]) {
            nums[idx++] = 2;
        }
    }
};
```

### 代码2（qsort三划分变形）
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lt = 0, i = 0, gt = nums.size()-1;
        while(i <= gt) {
            if(nums[i] < 1) swap(nums[i++], nums[lt++]);
            else if(nums[i] > 1) swap(nums[i], nums[gt--]);
            else i++;
        }
    }
};
```
