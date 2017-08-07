# Binary Tree Inorder Traversal

标签： 递归, 栈

---

## 题目描述

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree `[1,null,2,3]`,
```
   1
    \
     2
    /
   3
```
return `[1,3,2]`.

## 思路分析
一个经典的问题：二叉树的中序遍历。

递归解法不再详述，见代码1.

当尝试用非递归方法解决这个问题时，首先想到的是如何将递归过程用栈来描述？递归解法可以描述为：

```
找到当前子树最左边的节点，并用栈记录沿途经过的节点；
处理它；
转到这个节点的右子树（如果有的话），回到1.
右子树处理完之后，栈顶元素为沿途经过的最后一个节点，这时候对它进行同样操作
```

## 代码
### 代码1，naive的递归实现
```
c/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void recursiveInorder(TreeNode* root, vector<int>& ret) {
        if(root == nullptr) return;
        recursiveInorder(root->left, ret);
        ret.push_back(root->val);
        recursiveInorder(root->right, ret);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        recursiveInorder(root, ret);
        return ret;
    }
};
```
### 代码2，非递归实现
```
class Solution {
private:
    void findLeftMostNode(TreeNode* root, stack<TreeNode*>& s) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }
    void travel(stack<TreeNode*>& s, vector<int>& ret) {
        while(!s.empty()) {
            auto top = s.top();
            ret.push_back(top->val);
            s.pop();
            if(top->right) {
                s.push(top->right);
                findLeftMostNode(top->right->left, s);
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return vector<int>();
        vector<int> ret;
        stack<TreeNode*> s;
        findLeftMostNode(root->left, s);
        travel(s, ret);
        ret.push_back(root->val);
        findLeftMostNode(root->right, s);
        travel(s, ret);
        return ret;
    }
};
```
