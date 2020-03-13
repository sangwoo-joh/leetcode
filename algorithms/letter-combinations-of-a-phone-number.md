# [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

## Note
 - Input length could be any length.
 - If input has `1` in it, then the whole combinations would be empty.
 - When looping combination, the digit should be attached at suffix.
 - C++11 list initialization is very cool. `{}` represents empty.

## Solution

``` c++
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.find("1") != string::npos)
            return {};

        vector<vector<string>> digit_map = {
            {},
            {},
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
        };

        vector<string> answer;

        for (int depth = 0; depth < digits.length(); ++depth) {
            auto & digit_chars = digit_map[digits[depth] - '0'];

            vector<string> combinations;

            for (auto d : digit_chars){
                if (answer.empty()){
                    combinations.push_back(d);
                } else {
                    for(auto a : answer) {
                        combinations.push_back(a + d);
                    }
                }
            }

            answer = std::move(combinations);
        }

        return answer;
    }
};
```
