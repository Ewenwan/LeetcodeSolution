# Path Sum I && II

标签（空格分隔）： DFS Tree

---

## Path Sum
###描述
    Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

    For example:
    Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
    return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
###代码
* 12ms,但是不够简洁
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
public:
    void DFS(TreeNode* root, int sum, bool& flag)
    {
        if(flag)
            return;
        if(!root)
            return;
        if(!root->left && !root->right && sum == root->val)
        {
            flag = true;
            return ;
        }
        DFS(root->left, sum - root->val, flag);
        DFS(root->right, sum - root->val, flag);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        bool flag = false;
        DFS(root, sum, flag);
        return flag;
    }
};
```
* 16ms,学会使用或'||'
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
public:

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        if(!root->left && !root->right && sum == root->val)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
```
##Path Sum II
###描述
    Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

    For example:
    Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
    return
    [
       [5,4,11,2],
       [5,8,4,5]
    ]
###代码
* 20ms, 以当前节点的子节点考虑，分别对每个子节点做递归。
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
public:
    void DFS(TreeNode* root, int sum, int target, vector<int> r, vector<vector<int>>& result)
    {
        if(!root->left && !root->right)
        {
            if(sum == target)
                result.push_back(r);
            return;
        }
        if(root->left)
        {
            r.push_back(root->left->val);
            DFS(root->left, sum+ root->left->val, target, r, result);
            r.pop_back();
        }
        if(root->right)
        {
            r.push_back(root->right->val);
            DFS(root->right, sum+ root->right->val, target, r, result);
            r.pop_back();
        }
            
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(!root)   return result;
        vector<int> r;
        r.push_back(root->val);
        DFS(root, root->val, sum, r, result);
        return result;
    }
};
```
* 24ms, 以当前节点考虑，分别对子节点进行处理。
```
class Solution {
public:
    void DFS(TreeNode* root, int sum, vector<int> r, vector<vector<int>>& result)
    {
        if(!root)
            return;
        if(!root->left && !root->right && sum == root->val)
        {
            r.push_back(root->val);
            result.push_back(r);
            return;
        }
        r.push_back(root->val);
        DFS(root->left, sum - root->val, r, result);
        DFS(root->right, sum - root->val,r, result);
        r.pop_back();
            
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> r;
        DFS(root, sum, r, result);
        return result;
    }
};
```


