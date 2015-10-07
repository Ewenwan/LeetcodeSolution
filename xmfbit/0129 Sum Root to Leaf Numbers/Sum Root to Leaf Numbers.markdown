# Sum Root to Leaf Numbers

标签 ： DFS

---

## 题目描述
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path `1->2->3` which represents the number `123`.

Find the total sum of all root-to-leaf numbers.

For example,
```
    1
   / \
  2   3
```

The root-to-leaf path `1->2` represents the number `12`.
The root-to-leaf path `1->3` represents the number `13`.

Return the `sum = 12 + 13 = 25`. 

## 思路解析

这道题使用DFS来做是比较简单的。考虑当前节点是`cur`的时候，

  - `cur`是空的，那么直接返回即可。
  - `cur`是叶子节点，这时候就可以得到一条路径上的数了（也就是上例所示的`12`或者`13`）。这时候将它加到`sum`里面就好。
  - 其他情况，则把`cur`看作是根节点，递归的求解`cur`的左右子树的情况。

刚开始的时候，我认为只要分两种情况就可以，`cur`为`NULL`或`cur`不为`NULL`。但是这样就造成当`cur`是叶子节点的时候，考察它的左右两个空孩子，会使得这个叶子节点的数值被加上两次。所以有必要把叶子节点单独那出来考虑。
  
## 代码
```
class Solution {
private:
    int sum = 0;
    void dfs(TreeNode* curNode, int num) {
        if(curNode == nullptr)  return;
        num = num*10+curNode->val;
        if(curNode->left==nullptr && curNode->right==nullptr) {   // leave node
            sum += num;
            return;
        }
        else{
            dfs(curNode->left, num);
            dfs(curNode->right, num);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int num = 0;
        dfs(root, num);
        return sum;
    }
};
```




