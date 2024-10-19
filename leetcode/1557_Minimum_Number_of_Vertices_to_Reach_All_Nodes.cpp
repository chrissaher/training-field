// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> bag;
        unordered_set<int>::iterator it;
        for(int i = 0; i < n; ++i) bag.insert(i);
        for(auto &edge: edges) {
            it = bag.find(edge[1]);
            if(it != bag.end())
                bag.erase(it);
        }
        vector<int> answer;
        it = bag.begin();
        while(it != bag.end()) {
            answer.push_back(*it);
            it++;
        }
        return answer;
    }
};
