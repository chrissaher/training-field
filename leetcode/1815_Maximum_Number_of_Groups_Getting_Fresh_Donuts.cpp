// https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/

class Solution {
public:
    map<vector<int>, int> memo;
    int bt(vector<int> &vec, int left) {
        map<vector<int>,int>::iterator it = memo.find(vec);
        if(it != memo.end()) return it->second;
        int res = 0;
        int len = vec.size();
        for(int i = 1; i < len; ++i) {
            if(vec[i] > 0) {
                vec[i]--;
                res = max(res, (left == 0) + bt(vec, (left - i) % len));
                vec[i]++;
            }
        }
        return memo[vec] = res;

    }
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        int res = 0;
        vector<int> vec(batchSize);
        for(int group: groups) {
            int reminder = group % batchSize;
            if(reminder == 0)
                res++;
            else if(vec[batchSize - reminder] > 0 ) {
                vec[batchSize - reminder]--;
                res++;
            } else vec[reminder]++;
        }
        return bt(vec, 0) + res;
    }
};
