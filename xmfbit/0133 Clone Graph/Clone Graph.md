# Clone Graph

标签： graph dfs

---

## 题目描述
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. 
## 思路分析
我们可以使用DFS或者BFS的思想来遍历所给的待拷贝Graph，当访问到某节点时，则在内存中alloc一个新的节点，并从此新的节点开始dfs遍历它的邻接点。
```
copy(graph, copyed):
  for u in copyed:
    if u not visited:
      v = new Node(u)
      dfs(v, u)
```
其中`dfs`部分的伪代码为：
```
dfs(v, u):   // v 为新的Graph的节点，u为待拷贝图的节点
  mark v as visited
  for node in adj(u):   // 对于当前节点的邻接点
    if not visited(node):
      w = new(node)
      dfs(w, node)
    // 否则，node已经被访问过了，我们需要将它加入到当前节点的邻接表中去
```
## 代码

```
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    map<int, UndirectedGraphNode*> idx2node;  // 用来储存已经访问过的节点以及它们对应的节点指针
    void dfs(UndirectedGraphNode* u, UndirectedGraphNode* copyed) {
        idx2node[copyed->label] = u;
        for(const auto& node : copyed->neighbors) {
            map<int, UndirectedGraphNode*>::iterator it;
            if((it = idx2node.find(node->label)) != idx2node.end()) {
                // the node has been visited
                u->neighbors.push_back(it->second);
            } else {
                UndirectedGraphNode* v = new UndirectedGraphNode(node->label);
                dfs(v, node);
                u->neighbors.push_back(v);
            }
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        UndirectedGraphNode* start = new UndirectedGraphNode(node->label);
        dfs(start, node);
        return start;
    }
};
```


