# Reverse String

标签： string

---
## 题目描述
Write a function that takes a string as input and returns the string reversed.

Example:
Given `s = "hello"`, return `"olleh"`. 
## 思路分析
将字符串逆序，很简单，方法很多。
`swap(s[L-i], s[i]`即可.
或者两个指针，分别指向头尾，交换，分别向前向后遍历。
这里的代码使用了C++11中的逆序迭代器实现。
## 代码
```
class Solution {
public:
    string reverseString(string s) {
        string res;
        res.reserve(s.size());
        copy(s.rbegin(), s.rend(), back_inserter(res));
        return res;
    }
};
```




