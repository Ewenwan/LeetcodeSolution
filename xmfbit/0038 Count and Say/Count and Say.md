# Count and Say

标签： string

---
##题目描述
The count-and-say sequence is the sequence of integers beginning as follows:
`1, 11, 21, 1211, 111221, ...`

`1` is read off as "one 1" or `11`.
`11` is read off as "two 1s" or `21`.
`21` is read off as "one 2, then one 1" or `1211`.

Given an integer n, generate the nth sequence. 
##思路分析
这道题目通过求解数组中相邻相同元素的个数即可解决。
具体方法是使用两个游标，左侧游标负责指向当前要寻找的相同元素，右侧游标不断移动，直到达到边界或该处元素不再和左侧游标参考元素相同。接下来，更新左侧游标为当前右侧游标位置即可进行下一轮寻找。

##代码
```
class Solution {
    string readInteger(const string& integer) {
        string s("");
        int len = integer.length();
        int i = 0;
        while(i < len) {
            char ch = integer[i];   // 当前参考元素
            int j = i+1;
            while(j < len && integer[j] == ch) { // 移动右侧游标
                j++;
            }
            s += to_string(j-i) + string(1, ch);
            i = j;
        }
        return s;
    }
public:
    string countAndSay(int n) {
        string s("1");
        for(int i = 1; i < n; ++i) {
            s = readInteger(s);
        }
        return s;
    }
};
```
