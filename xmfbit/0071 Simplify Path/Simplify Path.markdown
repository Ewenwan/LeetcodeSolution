# Simplify Path

标签： stack

---

## 问题描述
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = `"/home/"`, => `"/home"`
path = `"/a/./b/../../c/"`, => `"/c"`

Corner Cases:
- Did you consider the case where path = `"/../"`?
In this case, you should return `"/"`.
- Another corner case is the path might contain multiple slashes `'/'` together, such as `"/home//foo/"`.
In this case, you should ignore redundant slashes and return `"/home/foo"`.
## 思路解析
这个问题是栈的典型应用场景。对字符串进行处理，得到目录名称后，使用栈来存储目录。这样当前栈顶元素即为当前目录的相对位置。
- 若该目录为`/..`，则将当前栈顶元素出栈（即进入其父目录）；
- 若该目录为`/.`，则什么都不做（即保留在当前目录）；
- 否则，则将新的目录压栈，即进行新的子目录。

思路是很明确的，在处理的时候需要注意corner case的处理。

- 对于情形1，注意当栈为空时（即已经进入了根目录），则即使遇到`/..`，也不pop；
- 对于情形2，注意在解析字符串得到目录名时，跳过相邻的`/`。


最后返回绝对路径时，我又使用了一个新的栈。这样，就能够顺序打印目录了。
## 代码

```
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> path_stack;
        int i = 0;
        while(i < path.size()) {
            // 处理情形2
            while(i+1 < path.size() && path[i+1] == '/') {
                ++i;
            }
            // 跳过字符串末尾的那个 “/”
            if(i+1 == path.size()) break;
            // parse for directory name
            int j = i+1;
            while(j < path.size() && path[j] != '/') {
                ++j;
            }
            string token_path = string(path, i, j-i);
            // 分情况处理
            if(token_path == "/..") {
                if(!path_stack.empty()) {
                    path_stack.pop();
                }
            } else if(token_path != "/.") {
                path_stack.push(token_path);
            }
            i = j;
        }
        if(path_stack.empty()) {
            return "/";
        }
        stack<string> reverse_stack;
        while(!path_stack.empty()) {
            reverse_stack.push(path_stack.top());
            path_stack.pop();
        }

        string ret;
        while(!reverse_stack.empty()) {
            ret += reverse_stack.top();
            reverse_stack.pop();
        }
        return ret;
    }
};
```
