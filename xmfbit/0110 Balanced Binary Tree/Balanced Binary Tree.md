# Balanced Binary Tree

标签： Tree

---
##题目描述
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

## 思路分析
如果用`h(node)`表示求取`node`在树中的高度，那么判定树是否平衡相当于下面的判定条件：
```
abs(h(node->left) - h(node->right)) <= 1
```
所以，我们应该能够在递归过程中传递高度`h`参量。某个节点的高度的计算也是很简单的：
```
h(node) = max{h(node->left), h(node->right)} + 1
```
然而，高度已经不能用作返回参数了，所以，可以使用引用使得这个参数在递归中被传递。

## 代码
```
class Solution {
    bool isBalanced(TreeNode* root, int& h) {
        if(root == nullptr) {   // 边界情况
            h = 0;
            return true;
        }
        int hl, hr;   // 记录左右孩子节点的高度
        if(!isBalanced(root->left, hl)) {   // 子树不平衡，该树自然不可能平衡
            return false;
        }
        if(!isBalanced(root->right, hr)) {
            return false;
        }
        h = max(hl, hr) + 1;         // 更新高度
        if(abs(hl-hr) > 1) return false;   // 不满足左右子树深度至多相差1
        return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h = 0;
        return isBalanced(root, h);
    }
};
```




