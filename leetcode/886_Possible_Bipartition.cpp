// https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool isConsistent(vector<vector<int> > &graph, vector<int> &visited, int parent, int u, int color) {
        visited[u] = color;
        for(int v: graph[u]) {
            if(v == parent) continue;
            if(visited[v] == color) return false;
            if(visited[v] == -1) {
                bool consistent = isConsistent(graph, visited, u, v, 1 - color);
                if(!consistent) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int> > graph(n);
        for(auto &edge: dislikes) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        vector<int> visited(n, -1);
        for(int i = 0; i < n; ++i) {
            if(visited[i] == -1)
                if(!isConsistent(graph, visited, -1, i, 0))
                    return false;
        }
        return true;
    }
};
