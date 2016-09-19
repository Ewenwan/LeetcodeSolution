# Construct Binary Tree from Preorder and Inorder Traversal

标签： 递归, tree

---
## 题目描述

## 思路分析
用实例分析，比如一棵树：
```
      1
     / \
    2   3
   /     \
  4       5
         /
        6 
```
先序遍历：
```
1 2 4 3 5 6
```
中序遍历：
```
4 2 1 3 6 5
```
首先，通过先序遍历可以直接得到根节点的值。然后我们在中序遍历中寻找这个值，就可以找出根节点在中序遍历中的位置。由于在中序遍历中，根节点左侧的数字都是左子树，右侧的数字都是右子树，所以我们再递归地重构左右子树即可。
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
    typedef pair<int, int> Pair;
    void reconstruct(vector<int>& preorder, vector<int>& inorder, TreeNode* root, int start, const Pair& p2) {
        int root_value = preorder[start];
        root->val = root_value;
        
        int i = p2.first;
        for(; i < p2.second; ++i) {
            if(inorder[i] == root_value) break;
        }
        // left sub-tree
        if(i == p2.first) {
            // left sub-tree is empty
            root->left = NULL;
        } else {
            TreeNode* left_child = new TreeNode(0);
            reconstruct(preorder, inorder, left_child, start+1, make_pair(p2.first, i));
            root->left = left_child;
        }
        // right sub-tree
        if(i == p2.second-1) {
            // right sub-tree is empty
            root->right = NULL;
        } else {
            TreeNode* right_child = new TreeNode(0);
            int left_size = i - p2.first;
            reconstruct(preorder, inorder, right_child, start+1+left_size, make_pair(i+1, p2.second));
            root->right = right_child;
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(0);
        reconstruct(preorder, inorder, root, 0, make_pair(0, preorder.size()));
        return root;
    }
};
```




