# Restore IP Addresses

标签： 递归

---

## 题目描述

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given `"25525511135"`,
return `["255.255.11.135", "255.255.111.35"]`. (Order does not matter)

## 思路分析
这个问题的关键在于递归当中的特殊情况考虑。（具体来说，就是ip地址中0的出现）

ip地址是32位正数，写出来的时候被分成4个字节，字节之间用'.'隔开。所以，每个数字都会在[0, 255]这个区间内。

所以开始我就写出了以下伪代码：
```
divideIP(string ip, int pos, int n, list solution)   // 将ip字符串中位置pos以后的部分分为n份，并满足要求
    if pos == ip.size() :
        if n == 0   // 同时要求n为0
            solution.push_back(这个解）
        return   
    for k = pos -> pos + 2:  // 因为最长也就3位（例如255）
        divideIP(ip, k+1, n-1, solution)
```
按照这个思路写出来的代码见代码段1.结果发现当字符串中有0的时候就会出错。所以，需要对0进行特殊处理。

当我们发现当前位置是0的时候，因为不可能出现`XX.00.XX.XX`的情况，所以只能是一个0单独占一个。所以我们直接将0压入解路径中，再进行递归处理即可。见代码2.

## 代码
### 代码1，没有考虑0这一特殊情况
```
class Solution {
    void bt(vector<vector<int>>& res, vector<int>& path, const string& s, int i, int n) {
        if(path.size() == 4) {
            if(i >= s.size())   res.push_back(path);
            return;
        }
        if(s.size() - i > 3 * n)    return;
        int add = 0;
        for(int k = i; k < i+3 && k < s.size(); ++k) {
            add = add * 10 + s[k] - '0';
            if(add > 255)   break;
            path.push_back(add);
            bt(res, path, s, k+1, n-1);
            path.pop_back();
        }
    }

    string int2ip(const vector<int>& ints) {
        string str;
        for(int i = 0; i < ints.size()-1; ++i) {
            str.append(to_string(ints[i]) + ".");
        }
        str.append(to_string(ints[3]));
        return str;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<int>> res;
        vector<int> path;
        bt(res, path, s, 0, 4);
        vector<string> ips;
        for(const auto& ints : res) {
            ips.push_back(int2ip(ints));
        }
        return ips;
    }
};
```
### 代码2，加上了对0的特殊处理
```
class Solution {
    void bt(vector<vector<int>>& res, vector<int>& path, const string& s, int i, int n) {
        if(path.size() == 4) {
            if(i >= s.size())   res.push_back(path);
            return;
        }
        if(s.size() - i > 3 * n)    
            return;  // 如果后续字符太多，已经不能分为n组3位数，那么直接返回
        if(s[i] == '0') {  // 特殊情况处理
            path.push_back(0);
            bt(res, path, s, i+1, n-1);
            path.pop_back();
        } else {
            int add = 0;
            for(int k = i; k < i+3 && k < s.size(); ++k) {
                add = add * 10 + s[k] - '0';
                if(add > 255)   break;
                path.push_back(add);
                bt(res, path, s, k+1, n-1);
                path.pop_back();
            }
        }
    }

    string int2ip(const vector<int>& ints) {
        string str;
        for(int i = 0; i < ints.size()-1; ++i) {
            str.append(to_string(ints[i]) + ".");
        }
        str.append(to_string(ints[3]));
        return str;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<int>> res;
        vector<int> path;
        bt(res, path, s, 0, 4);
        vector<string> ips;
        for(const auto& ints : res) {
            ips.push_back(int2ip(ints));
        }
        return ips;
    }
};
```
