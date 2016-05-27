# Reverse Vowels of a String

标签： two_pointer

---

## 题目描述
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = `"hello"`, return `"holle"`.

Example 2:
Given s = `"leetcode"`, return `"leotcede"`. 
## 思路
使用两个指针，分别从首尾遍历，每次均交换元音字母。
## 代码
```
class Solution {
    bool isVowel(char ch) {
        char c = tolower(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        int len = s.size();
        int i = 0, j = len - 1;
        while(i < j) {
            while(i < j && !isVowel(s[i])) {
                ++i;
            }
            while(j > i && !isVowel(s[j])) {
                --j;
            }
            if(i < j)   swap(s[i], s[j]);
            i++; --j;
        }
        return s;
    }
};
```



