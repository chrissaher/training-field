//https://leetcode.com/problems/license-key-formatting/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string new_key;
        int n = s.size();
        int group_size = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == '-') continue;
            char letter = s[i];
            // To Uppercase if possible
            if(letter >= 'a' && letter <= 'z') {
                letter = 'A' + int(letter - 'a');
            }
            new_key.push_back(letter);
            group_size++;
            if(group_size == k) {
                new_key.push_back('-');
                group_size = 0;
            }
        }
        int pos = new_key.size() - 1;
        while(pos >= 0 && new_key[pos] == '-') {
            new_key.pop_back();
            pos--;
        }

        reverse(new_key.begin(), new_key.end());
        return new_key;
    }
};
