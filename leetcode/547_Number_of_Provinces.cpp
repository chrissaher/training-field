// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:

    int numsets = 0;
    int findset(vector<int> &p, int i) {
        return (p[i] == i)? i: p[i] = findset(p, p[i]);
    }
    void unionset(vector<int> &p, int i, int j) {
        int pi = findset(p, i);
        int pj = findset(p, j);
        if(pi == pj) return;
        p[pi] = pj;
        numsets--;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int > parent(n);
        numsets = n;
        for(int i = 0; i < n; ++i) parent[i] = i;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                if(i != j && isConnected[i][j] == 1) 
                    unionset(parent, i, j);
        return numsets;
    }
};
