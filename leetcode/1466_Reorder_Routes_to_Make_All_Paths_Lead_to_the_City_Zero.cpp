// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int> > graph(n);
        set<pair<int,int> > edges;
        for(auto &edge: connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            edges.insert(make_pair(edge[0], edge[1]));
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        int to_reverse = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            visited[u] = true;
            for(auto &v: graph[u]) {
                if(visited[v]) continue;
                auto it = edges.find(make_pair(v, u));
                if(it == edges.end()) to_reverse += 1;
                q.push(v);
            }
        }
        return to_reverse;
    }
};
