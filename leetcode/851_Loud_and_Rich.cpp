// https://leetcode.com/problems/loud-and-rich/

class Solution {
public:

    int dfs(vector<vector<int> > &graph, vector<int> &quiet, vector<int> &memo, int u) {
        if(memo[u] != -1) return memo[u];
        memo[u] = u;
        for(int v: graph[u]) {
            int result_so_far = dfs(graph, quiet, memo, v);
            if(quiet[result_so_far] < quiet[memo[u]])
            memo[u] = result_so_far;
        }
        return memo[u];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int> > graph(n);
        for(auto & edge: richer) {
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> answer(n, -1);
        for(int i = 0; i < n; ++i)
            dfs(graph, quiet, answer, i);

        return answer;
    }
};
