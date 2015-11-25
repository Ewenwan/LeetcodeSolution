# Summary Ranges

标签： two_pointer

---

## 题目描述

Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given `[0,1,2,4,5,7]`, return `["0->2","4->5","7"]`.

## 思路分析
这道题也是一道双指针的问题。我们只需要用两个指针分别指向区间的开始和结束位置，在一趟遍历数组的过程中根据相邻两个元素是否是相邻的整数从而不断更新两个指针的位置就可以了。

```
begin, end = 0, 0
for i=1:n-1
    if a[i] == a[i-1]+1    // 说明相邻，那么我们需要更新的是end指针
        end = i;
    else   // 不相邻，说明一个连续区间已经被找到了，我们需要更新begin和end，同时输出这个区间
        push_back(tostring(begin, end));
        begin = end = i;
// 这里要注意，当循环完成之后，最后一个区间还没有被输出
push_back(tostring(begin, end));    // 不要忘记最后一个区间
```

## 代码
```
class Solution {
private:
    string itostring(int num1, int num2) {
        if(num1 == num2)
            return to_string(num1);
        else
            return to_string(num1) + "->" + to_string(num2);
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        size_t size = nums.size();
        if(size == 0)
            return vector<string>();
        vector<string> res;
        int begin = nums[0], end = nums[0];
        for(int i = 1; i < size; ++i) {
            if(nums[i] == nums[i-1]+1)  { // adjent
                end = nums[i];  //update end
            } else {
                res.push_back(itostring(begin, end));
                begin = nums[i];
                end = begin;
            }
        }
        res.push_back(itostring(begin, end));
        return res;
    }
};
```
这里一个点在于C++11在std空间中引入了一个新的函数`to_string`(http://www.cplusplus.com/reference/string/to_string/?kw=to_string)，可以很方便地将数字转换为字符串。




