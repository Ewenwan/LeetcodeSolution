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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int numsCurLayer, numsNextLayer = 1, layerIdx = 0;
        stack<int> sk;
        // BFS
        while(!dq.empty() && ++layerIdx)
        {
            // 这时候处理第i层，当i为奇数时，不倒置
            
			// 更新
            numsCurLayer = numsNextLayer;
            numsNextLayer = 0;
            
            res.push_back(vector<int>(numsCurLayer));
            vector<int>* ptr = &(res[res.size()-1]);
            
            bool isReverse = layerIdx % 2 == 0;
        
            int idx = 0;
            // deal with the ith layer
            
            while(numsCurLayer--)
            {
                // get the queue first element
                TreeNode* r = dq.front();
                if(isReverse)
                    sk.push(r->val);
                else
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
            if(isReverse)
            {
                idx = 0;
                while(!sk.empty())
                {
                    (*ptr)[idx++] = sk.top();
                    sk.pop();
                }
            }
        }
        return res;
    }
};