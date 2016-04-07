# Palindrome Linked List

标签： Linked_List two_pointer

---
## 题目描述
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
```
_______6______
/              \
___2__          ___8__
/      \        /      \
0      _4       7       9
 /  \
 3   5
```
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

## 思路解析

当`p`本就是`q`的祖先的时候，可以知道结果应该是`p`。
当两者没有这个关系的时候，根据二叉搜索树的递归性质，可以很容易判断出两个节点`p`和`q`的最近公共祖先，一定树中由根节点开始第一个介于两者之间的那个节点。

可以用反证法证明。假设这个节点不是LCA，那么说明`p`和`q`节点一定同时位于这个节点的左子树或者右子树，这就与该节点的值处于`p`和`q`之间矛盾。

## 代码

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(p == nullptr)    return q;
        if(q == nullptr)    return p;
        if(p == root || q == root)  return root;   // 特殊情况
        int minV = min(p->val, q->val);
        int maxV = max(p->val, q->val);
        if(root->val > minV && root->val < maxV) return root;  // 找到了两者之间的这个节点
        if(root->val < minV) return lowestCommonAncestor(root->right, p, q);  // 递归地在右子树中寻找
        else return lowestCommonAncestor(root->left, p, q);  // 递归地在左子树中寻找
    }
};
```
