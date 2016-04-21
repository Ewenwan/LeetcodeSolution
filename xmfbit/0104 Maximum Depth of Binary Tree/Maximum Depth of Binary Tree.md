# Maximum Depth of Binary Tree

标签： tree

---

## 题目描述
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## 思路分析
很简单，
```
H(r) = max(H(r->left), H(r->right)) + 1
H(nullptr) = 0  // 递归基
```
## 代码
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
```



