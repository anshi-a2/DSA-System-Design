//PROBLEM :

We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
  
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
  
Example 3:

Input: s1 = "a", s2 = "a"
Output: true



// SOLUTION :

class Solution {
public:
    // Memoization map:
    // Key  -> "s1 s2" (concatenated strings)
    // Value -> true/false indicating whether s2 is a scramble of s1
    unordered_map<string, bool> mp;

    bool isScramble(string s1, string s2) {

        // Lengths of both strings
        int n1 = s1.size();
        int n2 = s2.size();

        // If lengths differ, they cannot be scrambles
        if (n1 != n2) return false;

        // If strings are exactly equal, they are trivially scrambles
        if (s1 == s2) return true;

        // If length is 1 and strings are not equal, scramble is impossible
        if (n1 == 1) return false;

        // Create a unique key for memoization
        // Space is used to avoid ambiguity between strings
        string concatedString = s1 + " " + s2;

        // If result is already computed, return it directly
        if (mp.find(concatedString) != mp.end()) {
            return mp[concatedString];
        }

        // Try all possible partition positions
        for (int i = 1; i < n1; i++) {

            // Case 1: Without swap
            // s1[0..i) matches s2[0..i)
            // s1[i..n) matches s2[i..n)
            bool withoutSwap =
                isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i));

            // If any partition works, return true
            if (withoutSwap) return true;

            // Case 2: With swap
            // s1[0..i) matches s2[n-i..n)
            // s1[i..n) matches s2[0..n-i)
            bool withSwap =
                isScramble(s1.substr(0, i), s2.substr(n1 - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n1 - i));

            // If swap case works, return true
            if (withSwap) return true;
        }

        // If no partition leads to a valid scramble,
        // store result in memoization map and return false
        return mp[concatedString] = false;
    }
};
