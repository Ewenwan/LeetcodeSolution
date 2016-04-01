# Course Schedule

标签： graph theory

---
## 题目描述
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

`2, [[1,0]]`

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

`2, [[1,0],[0,1]]`

There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

## 思路分析
判断有向图G是否存在拓扑排序。由于没有要求输出拓扑排序的结果，所以只需要判断是否存在回路即可。如果存在回路`(u->v->u)`则说明不存在拓扑排序。

问题转换为了判断图中是否存在回路，可以通过深度优先搜索判断是否存在反向边来解决。在DFS过程中，我们根据某一点u以及该点的子节点（所谓子节点是指从u出发，能够达到的那些点）是否被访问完成，将点的状态分为：

 - WHITE 说明该点还未被访问过，还处在未知区域
 - GRAY 说明该点已经被访问过，目前我们正在访问该点的子节点
 - BLACK 说明该点已经被访问过，而且它的子节点也已经访问完成

这样，如果我们在遇到节点u发现其状态为GRAY的时候（u的状态为GRAY，说明我们正在访问其子节点，然而我们又遇到了u，说明存在某个u的子节点v，使得路径(u, v, u)存在，则该边是反向边，存在环路）。

DFS的伪代码如下：

```
// 初始化，所有节点state为WHITE
for u in G:
    if state(u) == WHITE:
        dfs(u, G, state)
        
dfs(u, G, state):
    state[u] = GRAY
    for v in ADJ(u):  // 对于所有u的邻接点
        if state[v] == WHITE:
            dfs(v, G, state)
    state[u] = BLACK  // u的所有子节点已经被访问完成
```

我们需要做的，就是当出现访问节点状态为GRAY的时候，返回。

## 代码
```
class Solution {
    enum {WHITE = 0, BLACK = 1, GRAY = 2};
    bool dfs(const vector<list<int>>& adj, int u, vector<unsigned char>& state) {
        state[u] = GRAY;
        for(int v : adj[u]) {
            if(state[v] == GRAY)    return false;
            if(state[v] == WHITE && !dfs(adj, v, state))    return false;
        }
        state[u] = BLACK;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 建立邻接表
        vector<list<int>> adj(numCourses, list<int>());
        for(const auto& p : prerequisites) {
            adj[p.first].push_back(p.second);
        }
        // 初始化state为未访问
        vector<unsigned char> state(numCourses, WHITE);
        for(int i = 0; i < numCourses; ++i) {
            if(state[i] == GRAY)    return false;
            if(state[i] == WHITE && !dfs(adj, i, state))    return false;
        }
        return true;
    }
};
```




