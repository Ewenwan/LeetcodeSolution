# Construct Binary Tree from Inorder and Postorder Traversal

标签： tree, 递归

---

## 题目描述
Given inorder and postorder traversal of a tree, construct the binary tree.
## 思路分析
这个问题和[105 Construct Binary Tree from Preorder and Inorder Traversal](../0105 Construct Binary Tree from Preorder and Inorder Traversal/Construct Binary Tree from Preorder and Inorder Traversal.md)相似，可以采用相同的思路。
关键点就是在找到根节点后，如何划分出左右子树，并进行递归。
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
class Solution {
    void reconstruct(vector<int>& inorder, vector<int>& postorder, int end, 
                     const pair<int, int>& p, TreeNode* root) {
        int root_value = postorder[end];
        root->val = root_value;
        int idx = p.first;
        for(; idx < p.second; ++idx) {
            if(inorder[idx] == root_value)  break;
        }
        int size_left_tree = idx - p.first;
        int size_right_tree = p.second - idx - 1;
        // left sub-tree
        if(size_left_tree == 0) {
            // empty left sub-tree
            root->left = NULL;
        } else {
            TreeNode* left = new TreeNode(0);
            root->left = left;
            reconstruct(inorder, postorder, end-size_right_tree-1, make_pair(p.first, idx), left);
        }
        if(size_right_tree == 0) {
            // empty right sub-tree
            root->right = NULL;
        } else {
            TreeNode* right = new TreeNode(0);
            root->right = right;
            reconstruct(inorder, postorder, end-1, make_pair(idx+1, p.second), right);
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        TreeNode* root = new TreeNode(0);
        reconstruct(inorder, postorder, postorder.size()-1, make_pair(0, inorder.size()), root);
        return root;
    }
};
```



