//https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 0; i < n; ++i) {
            int index = i + 1;
            bool divisibleBy3 = (index % 3 == 0);
            bool divisibleBy5 = (index % 5 == 0);
            if(divisibleBy3 && divisibleBy5) {
                res.push_back("FizzBuzz");
            } else if(divisibleBy3) {
                res.push_back("Fizz");
            } else if(divisibleBy5) {
                res.push_back("Buzz");
            } else {
                res.push_back(to_string(index));
            }
        }
        return res;
    }
};
