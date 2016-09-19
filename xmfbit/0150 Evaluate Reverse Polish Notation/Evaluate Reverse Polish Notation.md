# Evaluate Reverse Polish Notation

标签：stack
---

## 题目描述
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
```
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
```
## 思路分析
stack的简单应用。由于已经是以逆波兰算式的形式给出，所以直接使用一个stack用来盛放数字即可。

## 代码
```
class Solution {
    int op(int a1, int a2, char ch) {
        switch(ch) {
            case '+':
                return a1+a2;
            case '-':
                return a1-a2;
            case '*':
                return a1*a2;
            case '/':
                return a1/a2;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        set<string> ops{"+", "-", "*", "/"};
        stack<int> numbers;
        for(const auto& s: tokens) {
            if(ops.find(s) == ops.end()) {
                numbers.push(atoi(s.c_str()));
            } else {
                int n1 = numbers.top();
                numbers.pop();
                int n2 = numbers.top();
                numbers.pop();
                int res = op(n2, n1, s[0]);
                numbers.push(res);
            }
        }
        return numbers.top();
    }
};
```



