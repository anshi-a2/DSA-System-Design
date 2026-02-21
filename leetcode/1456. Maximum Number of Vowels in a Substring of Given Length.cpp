// PROBLEM :

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
  
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.


// SOLUTION :

class Solution {
public:
    bool isVowel(char &c)
    {
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }

    int maxVowels(string s, int k) {
        
        int ans=0,count=0, left=0, right=k;
        for(int i=0; i<k; i++)
        {
            if(isVowel(s[i]))
            {
                count++;
            } 
        }
        ans = count;

        while(right<s.size())
        {
            if(ans==k)return ans;// ans can't be greater than k

            if(isVowel(s[left])) count--;
            if(isVowel(s[right]))count++;

            left++;
            right++;

            ans = max(ans,count);
        }
        //CAN ALSO BE WRITTEN THIS WAY
        //  // slide window
        // for (int i = k; i < s.size(); i++) {
        //     if (isVowel(s[i])) count++;       // add right
        //     if (isVowel(s[i - k])) count--;   // remove left
        //     ans = max(ans, count);
        // }

        return ans;
    }
};
