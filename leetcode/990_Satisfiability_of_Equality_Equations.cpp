// https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
public:
    int findset(vector<int> &p, int i) {
        return (p[i] == i)? i: p[i] = findset(p, p[i]);
    }

    void unionset(vector<int> &p, int i, int j) {
        int pi = findset(p, i);
        int pj = findset(p, j);
        if(pi != pj) p[pi] = pj;
    }

    bool issameset(vector<int> &p, int i, int j) {
        return findset(p, i) == findset(p, j);
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parents(30);
        for(int i = 0; i < 30; ++i) parents[i] = i;

        for(string &eq: equations) {
            char var1 = eq[0], var2 = eq[3];
            int index1 = int(var1 - 'a'), index2 = int(var2 - 'a');
            if(eq[1] == '=') unionset(parents, index1, index2);
        }

        for(string &eq: equations) {
            char var1 = eq[0], var2 = eq[3];
            int index1 = int(var1 - 'a'), index2 = int(var2 - 'a');
            if(eq[1] == '!' and issameset(parents, index1, index2))
                return false;
        }
        return true;
    }
};
