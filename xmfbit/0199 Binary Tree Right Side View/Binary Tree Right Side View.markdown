# Binary Tree Right Side View

标签： tree DSF

---

## 题目描述
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
```
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
```
You should return `[1, 3, 4]`. 

## 思路解析
这道题相当于寻找一条根节点到叶子节点最右的“路径“。这里我给路径加上引号，是因为结果很可能并不是真正的”连通“路径，或者说有可能有下面的情况发生：
```
     1          
   /   \
  2     3        
 / 
4        
```
这时候，答案为`[1->3->4]`，就不是一条真正的从根节点1到叶子节点的路径。

解题思路还是使用递归的DFS。我们的思考方法应该是考虑如何减小问题的规模。也就是如果找到了一个节点`root`，那么接下来要如何决策才能够找到由当前的`root`节点出发存在的”路径“呢？

在我解决这个问题的时候，从题目描述入手，先考虑比较简单的情况（比如题目描述的那种），应该是尽量去找贴近右侧的路径。
```
dfs(root, path):
    if root 是空的:
        return
    else
        path.push_back(root)
        if(root->right):    // 如果右孩子存在
            dfs(root, path)
        else if(root->left)   // 右孩子没有，只能从左孩子找了
            dfs(root, path)
```
这样做，就能够一直贴着右侧去寻找路径了。但是这种方法对于上面提出的那种不连续路径是没有办法的。所以还需要改进。

从上面可以看到，我们不能只寻找最右边的路径，其实在栈在当前节点思考下一步的决策中，我们应该是左右子树一起来找。那么我们怎么确定左右子树选哪个呢？

 - 应该优选选择右树。因为如果右树存在，就一定会”遮挡“左树。
 - 当**当前层**不存在右树的时候，选择左树。

所以，我想引入了一个`int`变量来存储函数参数`path`的元素个数，不过如果使用C++的`vector`的话，就不用了。因为直接访问`vector.size()`就可以得到路径的长度。

## 代码
```
class Solution 
{
private:
    void dfs(TreeNode* root, vector<int>& path)
    {
        if(root == NULL)    return;
        path.push_back(root->val);       // 加入当前节点值
        if(root->left == NULL && root->right == NULL)   return;  // 已经是叶子节点了
        vector<int> rightP, leftP;
        // 递归左右子树
        dfs(root->right, rightP);
        dfs(root->left, leftP);
        // leftP 和 rightP 的size() 即为路径长度，将其加入当前步已有的解path
        path.insert(path.end(), rightP.begin(), rightP.end());
        if(leftP.size() > rightP.size())
            path.insert(path.end(), leftP.begin() + rightP.size(), leftP.end());
    }
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL)    return res;
        dfs(root, res);
        return res;
    }
};
```



