# Path Sum

标签： tree

---
## 题目描述
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. 

## 思路解析
树的递归结构使得递归成为解决和二叉树有关的问题的一种常用方法。这道题也可以用递归来做。

可以想象，如果存在一条由root到叶子节点的路径，使得和为sum，那么这条路径上的第二个节点到该叶子节点的和必为 `sum-root->val`
于是，`hasPathSum(TreeNode* root, int sum) = hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val)` 

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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root == NULL)
            return false;
        else if(root->left == NULL && root->right == NULL)
            return root->val == sum;
        else // has left children or right children
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);   
    }
};
```
至于这个问题的DST解法，留到Path Sum II中。



