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
    // 检验两个节点是否成镜像关系
    bool isMirror(TreeNode* ltree, TreeNode* rtree)
    {
        // 先把边界条件搞清
        if(ltree == NULL)
            return rtree == NULL;
        if(rtree == NULL)
            return ltree == NULL;
        // 当两个节点都非NULL时候，需要判定节点值是否相同，且(左节点的右孩子右节点的左孩子)(左节点的左孩子右节点的右孩子) 镜像  
        return ltree->val == rtree->val && isMirror(ltree->left, rtree->right) && isMirror(ltree->right, rtree->left);
    }
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        return isMirror(root->left, root->right);
    }
};