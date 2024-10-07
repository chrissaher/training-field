// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> dict;
        unordered_map<string, int> candidates;
        int size_list1 = list1.size();
        int size_list2 = list2.size();
        for(int i = 0; i < size_list1; ++i) {
            dict[list1[i]] = i;
        }

        int least_index_sum = size_list1 + size_list2;
        unordered_map<string, int>:: iterator it;
        for(int i = 0; i < size_list2; ++i) {
            it = dict.find(list2[i]);
            if(it != dict.end()) {
                int candidate_index_sum = it->second + i;
                candidates[list2[i]] = candidate_index_sum;
                if(least_index_sum > candidate_index_sum)
                    least_index_sum = candidate_index_sum;
            }
        }

        vector<string> res;
        for(it = candidates.begin(); it != candidates.end(); ++it) {
            if (least_index_sum == it->second) {
                res.push_back(it->first);
            }
        }
        
        return res;
    }
};
