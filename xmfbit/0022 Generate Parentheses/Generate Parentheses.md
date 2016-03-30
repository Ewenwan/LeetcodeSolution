# Generate Parentheses

标签： backtracking

---
## 题目描述
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given `n = 3`, a solution set is:

`"((()))", "(()())", "(())()", "()(())", "()()()"` 

## 思路分析

这个问题可以通过构造一颗二叉树求解。一条通路就是一个解。根节点是空，表明当前的解中没有元素。之后的左右孩子分别表示下一步取左括号还是右括号。

其实是在求解一颗二叉树的符合要求的从根节点到叶子的通路，要求这个通路上任意一个位置，左括号的数量应该不小于右括号。所以直接使用深度优先搜索就可以了。也就是回溯的同时，对左括号数量小于右括号的路径及时剪枝。

## 代码
```
class Solution {
    void bt(vector<string>& res, const string& s, int lcnt, int rcnt, int n) {
        if(lcnt == rcnt && lcnt == n) {   //到达了叶子节点
            res.push_back(s);
            return;
        }
        if(lcnt > n || rcnt > lcnt) return;  // 括号不匹配，及时返回
        bt(res, s + "(", lcnt+1, rcnt, n);
        bt(res, s + ")", lcnt, rcnt+1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        bt(res, "", 0, 0, n);
        return res;
    }
};
```

