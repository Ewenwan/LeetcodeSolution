# Reverse Words in a String

标签： two_pointer

---

## 题目描述
Given an input string, reverse the string word by word.

For example,
Given `s = "the sky is blue"`,
return `"blue is sky the"`. 

## 思路分析
使用两个指针，一个指针从后向前遍历字符串`s`，用于定位`word`的词尾；另一个指针从该指针出发向前遍历，用来定位`word`的词头。将每个`word`插入到字符串末尾。

## 代码
```
class Solution {
public:
    void reverseWords(string &s) {
        string tmp;
        int len = s.size();
        int i = len - 1;
        while(i >= 0 && isspace(s[i]))  --i;
        while(i >= 0) {
            int j = i;
            while(j >= 0 && !isspace(s[j])) --j;
            if(!tmp.empty())    tmp.push_back(' ');
            tmp.append(s, j + 1, i - j);
            while(j >= 0 && isspace(s[j])) --j;
            i = j;
        }
        s = tmp;
    }
};
```

