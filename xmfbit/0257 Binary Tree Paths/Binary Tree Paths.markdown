# Binary Tree Paths

标签： tree DFS
## 题目描述
---
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
```
   1
 /   \
2     3
 \
  5
```
All root-to-leaf paths are:
```
["1->2->5", "1->3"]
```
## 思路解析
递归DFS，看了Wang的递归DFS之后用这道题来练手。
一个需要注意的地方：

- 代码中的`string s`是值传递的，这样能够使得每次回溯的时候能够恢复原来的状态。 

## 代码
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
private:
    char buf[10];
    
    void dfs(TreeNode* root, string s, vector<string>& sol)
    {
        if(root == NULL)    return;
        if(root->left == NULL && root->right == NULL)   // find
        {
            sprintf(buf, "%d", root->val);
            s.append(string(buf));
            sol.push_back(s);
            return;
        }
        sprintf(buf, "%d", root->val);
        s.append(string(buf));
        s.append("->");
        dfs(root->left, s, sol);
        dfs(root->right, s, sol);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        string s;
        dfs(root, s, res);
        return res;
    }
};
```



