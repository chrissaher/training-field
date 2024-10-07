// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n == 0) return nums2;
        if(m == 0) return nums1;
        int it1 = 0, it2 = 0;

        vector<vector<int>> merged;
        while(it1<n || it2 < m) {
            if(it1 >= n) {
                merged.push_back(nums2[it2++]);
                continue;
            }
            if(it2 >= m) {
                merged.push_back(nums1[it1++]);
                continue;
            }
            vector<int> curr1 = nums1[it1];
            vector<int> curr2 = nums2[it2];
            if(curr1[0] == curr2[0]) {
                it1++;
                it2++;
                merged.push_back({curr1[0], curr1[1] + curr2[1]});
            } else if(curr1[0] < curr2[0]) {
                it1++;
                merged.push_back(curr1);
            } else {
                it2++;
                merged.push_back(curr2);
            }
        }
        return merged;
    }
};
