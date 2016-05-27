class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> reverse_order;
        reverse_order.reserve(numCourses);
        vector<vector<int>> adjacency_list(numCourses);
        for (auto &edge : prerequisites) {
            adjacency_list[edge.second].push_back(edge.first);
        }
        vector<int> marked(numCourses, 0);  // 0: not marked 1: being used 2: marked
        for (int v = 0; v < numCourses; ++v) {
            if (marked[v] == 0) {
                bool res = dfs(v, adjacency_list, marked, reverse_order);
                if (!res) return vector<int>{};
            }
        }
        return vector<int>{reverse_order.rbegin(), reverse_order.rend()};
    }
    
    // precondition: marked[v] == 0
    bool dfs(int v, const vector<vector<int>> &adjacency_list, vector<int> &marked, vector<int> &reverse_order) {
        marked[v] = 1;
        for (auto to : adjacency_list[v]) {
            if (marked[to] == 1) return false;
            if (marked[to] == 0) {
                bool res = dfs(to, adjacency_list, marked, reverse_order);
                if (!res) return false;
            }
        }
        marked[v] = 2;
        reverse_order.push_back(v);
        return true;
    }
};