# Letter Combinations of a Phone Number

标签：back_tracking

---

## 题目描述
Given a digit string, return all possible letter combinations that the number could represent.

Input:Digit string `"23"`
Output: `["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]`.

## 思路分析
比较简单的递归题目。
```
solve(res, digit): 
  if digit 为空： // 递归基
    将空字符串加入res中
    return
  // 问题规模减1，递归
  // 处理当前深度，将当前元素加入
```
## 代码
```
static string maps[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
    string dig2letter(char dig) {
        return maps[dig - '0'];
    }
    void bt(vector<string>& res, const string& dig, int end) {
        if(end == 0) {
            res.push_back(string(""));
            return;
        }
        bt(res, dig, end - 1);
        int size = res.size();
        for(int i = 0; i < size; ++i) {
            auto s = res[i];
            auto letters = dig2letter(dig[end - 1]);
            res[i].push_back(letters[0]);
            for(int j = 1; j < letters.size(); ++j) {
                s.push_back(letters[j]);
                res.push_back(s);
                s.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())  return vector<string>();
        vector<string> res;
        bt(res, digits, digits.size());
        return res;
    }
};
```



