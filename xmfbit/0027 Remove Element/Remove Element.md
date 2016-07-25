# Remove Element

标签： two_pointer

---

## 题目描述
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
## 思路分析
循环不变式是个好东西！
思路：我们扫这个数组一遍，如果发现了想要删除的这个值，那么怎么删除它呢？朴素的方法是后面的元素一个个往前挪一个单位就可以了，然而杀鸡焉用牛刀。由于题目不要求保持数组原有的顺序，那么我们直接拿末尾元素覆盖掉它好了！当然，这时候需要标记数组的尾巴在哪里（或者说是标记数组的实际长度）。沿着这个思路，很自然的，发现需要两个指针。一个指向待处理的元素，一个指向数组的尾部。分别称为i和j好了。
于是可以写出下面的循环不变式。在每次迭代前：
[0, i)范围内是已经处理过的元素，保证不含有待找元素val;
[i, j]之间是待处理元素们，其中j是最后一个元素的位置。
那么通过下面这个选择逻辑，循环不变式可以在该次迭代后保持不变！
```
if a[i] == val then a[i] = a[j]; j--;
else i++;
```
初始情况下，`i=0, j = n-1`，循环不变式成立。所以可以推知算法的正确性。
## 代码
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size()-1;
        while(i <= j) {
            if(nums[i] == val) nums[i] = nums[j--];
            else ++i;
        }
        return j+1;
    }
};
```