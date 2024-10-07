// https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    string store(vector<int> &nums, int i, int j) {
        if(i + 1 == j) return to_string(nums[i]);
        return to_string(nums[i]) + "->" + to_string(nums[j - 1]);
    }

    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return vector<string>();
        int L = 0, R = 0;
        vector<string> result;
        while(L < n) {
            R = L + 1;
            while(R < n && nums[R - 1] + 1 == nums[R]) {
                R++;
            }
            result.push_back(store(nums, L, R));
            L = R;
        }
        return result;
    }
};
