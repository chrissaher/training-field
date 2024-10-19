// https://leetcode.com/problems/maximum-star-sum-of-a-graph/

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        if(n == 0) return 0;
        vector<vector<int> > graph(n);
        for(auto & edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(vals[v]);
            graph[v].push_back(vals[u]);
        }
        int ans = vals[0];
        for(int i = 0; i < n; ++i) {
            auto &weights = graph[i];
            sort(weights.begin(), weights.end());
            int l = weights.size() - 1, acum = vals[i];
            ans = max(ans, acum);
            int taken = 0;
            while(l >= 0 && taken < k) {
                acum += weights[l--];
                ans = max(ans, acum);
                taken++;
            }
        }
        return ans;
    }
};
