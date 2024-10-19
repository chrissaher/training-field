// https://leetcode.com/problems/minimum-cost-to-convert-string-i/

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 200000000LL;
        int m = int('z'-'a') + 2;
        vector<vector<int> > graph(m, vector<int>(m, INF));
        int n = cost.size();
        for(int i = 0; i < n; ++i) {
            int u = int(original[i] - 'a');
            int v = int(changed[i] - 'a');
            graph[u][v] = min(graph[u][v], cost[i]);
        }

        for(int i = 0; i < m; ++i) graph[i][i] = 0;

        // floyd-warshall
        for(int k = 0; k < m; ++k)
            for(int i = 0; i < m; ++i)
                for(int j = 0; j < m; ++j) {
                    if(graph[i][k] == INF) continue;
                    if(graph[k][j] == INF) continue;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
        
        int len = source.size();
        if(int(target.size()) != len) return -1;
        long long totalcost = 0;
        for(int i = 0; i < len; ++i) {
            int u = int(source[i] - 'a');
            int v = int(target[i] - 'a');
            if(graph[u][v] == INF) return -1;
            totalcost += graph[u][v];
        }
        return totalcost;
    }
};
