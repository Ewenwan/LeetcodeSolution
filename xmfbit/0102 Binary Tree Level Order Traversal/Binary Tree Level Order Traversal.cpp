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
	// ��α��� BFS
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == NULL)    return res;
        deque<TreeNode*> dq;
        dq.push_back(root);
		// current layer �� next layer �Ľڵ����
        int numsCurLayer, numsNextLayer = 1;
		// BFS
        while(!dq.empty())
        {
			// ����
            numsCurLayer = numsNextLayer;
            numsNextLayer = 0;
            
            res.push_back(vector<int>(numsCurLayer));
            vector<int>* ptr = &(res[res.size()-1]);
            int idx = 0;
            // deal with the ith layer
            while(numsCurLayer--)
            {
                // get the queue first element
                TreeNode* r = dq.front();
                (*ptr)[idx++] = r->val;
                if(r->left != NULL)
                {
                    dq.push_back(r->left);
                    ++ numsNextLayer;
                }
                if(r->right != NULL)
                {
                    dq.push_back(r->right);
                    ++ numsNextLayer;
                }
                dq.pop_front();
            }
        }
        return res;
    }
};