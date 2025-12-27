// PROBLEM :

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
  
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
  
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


// SOLUTION :

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        // dp[i][j] = true if first i chars of s match first j chars of p
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty string matches empty pattern
        dp[0][0] = true;

        // Initialize first row: s is empty, p may contain '*'
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // '*' can match empty (dp[i][j-1])
                // or match one/more characters (dp[i-1][j])
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }

                // '?' matches any single character
                // or exact character match
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};


