//https://leetcode.com/problems/range-addition-ii/


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_m = m, min_n = n;
        int x, y;
        for(auto & coord: ops) {
            x = coord[0];
            y = coord[1];
            min_m = min(min_m, x);
            min_n = min(min_n, y);
        }
        return min_m * min_n;
    }
};
