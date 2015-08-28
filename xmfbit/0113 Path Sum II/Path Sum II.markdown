# Path Sum II

标签： tree DFS

---
## 题目描述
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum. 

## 思路解析
这个问题和Path Sum的区别在于要求找出所有的可行路径。由于是从根节点到叶子节点的寻路问题，所以采用DST的思路。
```
根节点入栈
while 栈不空:
    取栈顶元素
    if 栈顶元素为叶子节点:
       if cursum == sum :  // 找到了一组解
            输出
       else
            stack.pop()   // 出栈
            cursum -= top->val
    else
       if 左孩子存在 && 还未被访问过:
            左孩子结点入栈
            cursum += lchild->val
       else if 右孩子存在 && 还未被访问:
            cursum += rchild->val;
      else:    // 说明左右孩子均已经访问过了
            stack.pop()    // 出栈
            cursum -= top->val
```
在实际解题中，为了能够标记左右孩子是否被访问过了，我只好又建了一个栈专门用来存在nodestack对应位置元素没有被访问过的孩子的个数。

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
private:
    stack<TreeNode*> nodeSK;
    stack<int> childSK;
    vector<int> getResult()
    {
        stack<int> nums;
        stack<TreeNode*> tmp(nodeSK);
        while(!tmp.empty())
        {
            nums.push(tmp.top()->val);
            tmp.pop();
        }
        vector<int> res;
        while(!nums.empty())
        {
            res.push_back(nums.top());
            nums.pop();
        }
        return res;
    }
    
    int getChildrenNumber(TreeNode* node)
    {
        if(node->left != NULL)
        {
            if(node->right != NULL)
                return 2;
            else return 1;
        }
        if(node->right)
            return 1;
        return 0;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> res;
        if(!root)   return res;
        nodeSK.push(root);
        childSK.push(getChildrenNumber(root));
        int curSum = root->val;
        
        while(!nodeSK.empty())
        {
            TreeNode* topNode = nodeSK.top();
            if(topNode->left == NULL && topNode->right == NULL)
            {
                if(curSum == sum)
                    res.push_back(getResult());
                nodeSK.pop();
                childSK.pop();
                curSum -= topNode->val;
            }
            else
            {
                TreeNode* child;
                int childNum = childSK.top();
                if(childNum == 0)
                {
                    nodeSK.pop();
                    childSK.pop();
                    curSum -= topNode->val;
                }
                else
                {
                    if(childNum == 1)
                    {
                        child = topNode->right;
                        if(child == NULL)
                            child = topNode->left;
                    }
                    else
                        child = topNode->left;
                    childSK.top() -= 1;
                    nodeSK.push(child);
                    curSum += child->val;
                    childSK.push(getChildrenNumber(child));
                }
            }
        }
        return res;
    }
};
```




