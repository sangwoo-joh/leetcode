class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        register int dp[10000] = {0,};
        int ans = 0, flag = 0;
        for (register int i=0; i<s.size(); i++){
            flag = flag > dp[s[i]] ? flag : dp[s[i]];
            ans = ans > i + 1 - flag ? ans : i + 1 - flag;
            dp[s[i]] = i+1;
        }
        return ans;
    }
};
