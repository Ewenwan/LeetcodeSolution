# Course Schedule II

标签： graph_theory

---
## 题目描述
 There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

`2, [[1,0]]`

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

`4, [[1,0],[2,0],[3,1],[3,2]]`

There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
## 思路分析
见 0207题 "Course Schedule"。
需要加入一个辅助变量，用来储存当前步的结果。
## 代码
```
class Solution {
    enum {WHITE = 0, BLACK = 1, GRAY = 2};
    bool dfs(vector<int>& path, const vector<list<int>>& adj, int u, vector<unsigned char>& state) {
        state[u] = GRAY;
        for(int v : adj[u]) {
            if(state[v] == GRAY)    return false;
            if(state[v] == WHITE && !dfs(path, adj, v, state))  return false;
        }
        state[u] = BLACK;
        path.push_back(u);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int>> adj(numCourses, list<int>());
        for(const auto& p : prerequisites) {
            adj[p.first].push_back(p.second);
        }
        //stack<int> inv_path;
        vector<int> res;
        vector<unsigned char> state(numCourses, WHITE);
        for(int i = 0; i < numCourses; ++i) {
            if(state[i] == GRAY)    return vector<int>();
            if(state[i] == WHITE && !dfs(res, adj, i, state))    return vector<int>();
        }
        return res;
    }
};
```




