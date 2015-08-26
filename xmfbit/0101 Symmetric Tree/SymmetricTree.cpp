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
    // ���������ڵ��Ƿ�ɾ����ϵ
    bool isMirror(TreeNode* ltree, TreeNode* rtree)
    {
        // �Ȱѱ߽���������
        if(ltree == NULL)
            return rtree == NULL;
        if(rtree == NULL)
            return ltree == NULL;
        // �������ڵ㶼��NULLʱ����Ҫ�ж��ڵ�ֵ�Ƿ���ͬ����(��ڵ���Һ����ҽڵ������)(��ڵ�������ҽڵ���Һ���) ����  
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