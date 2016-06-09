# Longest Substring Without Repeating Characters

标签： two_pointer

---

## 题目描述
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

## 思路分析
找出字符串中满足不重复字符的子串的最大长度。可以使用两个指针，分别指向子串的起始和终了位置，当子串不再满足条件时。计算该子串的长度并和当前的最大长度比较。

当子串中出现重复字符的时候，如何更新指针呢？我们可以直接将起始指针更新为重复字符出现的位置后一位。因为潜在的最长子串不会再以这之间的某个位置作为起始位置了。（如果作为起始位置，那么必然会在小于这个子串长度的位置出现刚才发现的这个重复字符）。终了指针则直接加1即可。

## 代码
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())   return 0;
        int i = 0, j = 1, ml = 1, len = s.size();
        // s[i, ..., j-1] no repeated
        while(j < len && i + ml <= len) {
            char ch = s[j];
            int k = i;
            for(; k < j; ++k) {
                if(s[k] == ch) break;
            }
            if(k < j) {
                ml = max(ml, j - i);
                i = k + 1;
            }
            ++j;
        }
        return max(ml, j - i);
    }
};
```



