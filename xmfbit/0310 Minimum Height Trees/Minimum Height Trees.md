# Minimum Height Trees

标签： Graph

---
## 题目描述
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = `[[1, 0], [1, 2], [1, 3]]`
```
        0
        |
        1
       / \
      2   3
```
return `[1]`

Example 2:

Given n = 6, edges = `[[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]`
```
     0  1  2
      \ | /
        3
        |
        4
        |
        5
```
return `[3, 4]` 

题目大意：对于一类树状的图，考虑下面的问题：在图中任取一点为root，则原图成为一个rooted tree。问选取何点为root，可以使得tree的高度最小（即构造最小高度树MHT）。
附注：所谓“树”，即是指任意两个节点间有且仅有一条路径的无向图。

## 思路分析
这道题我是看了[讨论区的解答](https://discuss.leetcode.com/topic/30572/share-some-thoughts)才做出来的。这个人的思路是从特殊到一般，先考虑一个trival的问题，即如何在一个path graph当中寻找要求的root。这个问题很简单，直接找中点即为所求。然而这只是线性的情况，我们不妨就在这种线性的情况下思考一种通用解法？

关键一点在于如何求取中点？提出只要从path的两个端点同时向中间靠拢，直到最后只剩下一个节点或者两点节点（根据path上总的节点数是奇数还是偶数），这两个节点即为中点，也就是所求。

这时候需要我们从刚才的特殊情景推广到一般情景了。如果面对的是一个非线性的树状图呢？按照刚才的思路，我们只需要从树状图中的叶子节点（对应于刚才path graph中的两个端节点）开始遍历，每次迭代都删掉目前的叶子节点，直到剩下不多于两个节点，即为所求。

在代码中，我们可以记录每个节点的度。当通过某个叶子节点访问到该节点时，将节点的度减1（因为叶子节点被删掉了，故相应节点的度要减1）。每次遍历都保存当前度为1的节点作为叶子节点。这样，当叶子节点数目小于2的时候，这两个（或一个）节点就是所求节点。

## 代码
```
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj_list(n);
        for(const auto& e : edges) {
            adj_list[e.first].push_back(e.second);
            adj_list[e.second].push_back(e.first);
        }
        vector<int> degree;     // degree of nodes
        for(const auto& adj : adj_list) {
            degree.push_back(adj.size());
        }
        vector<int> leaves;    // leaves
        for(int i = 0; i < n; ++i) {
            if(adj_list[i].size() <= 1) {
                leaves.push_back(i);
            }
        }
        while(n > 2) {
            n -= leaves.size();
            vector<int> tmp_leaves;
            for(int v: leaves) {
                for(int u : adj_list[v]) {
                     if(degree[u] == 2) {
                         tmp_leaves.push_back(u);
                     }
                     degree[u]--;
                }
            }
            leaves = tmp_leaves;
        }
        return leaves;
    }
};
```

