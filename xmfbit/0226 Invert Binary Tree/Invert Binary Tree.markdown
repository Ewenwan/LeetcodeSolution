# Invert Binary Tree

标签：tree 

---

## 题目描述
Invert a binary tree. 

## 思路解析

这道题用递归很简单。

```
InvertTree(root):
    if root 有孩子:
        交换左右孩子
        Invert 左子树
        Invert 右子树
```

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
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
            return root;
        else
        {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
    }
};
```




