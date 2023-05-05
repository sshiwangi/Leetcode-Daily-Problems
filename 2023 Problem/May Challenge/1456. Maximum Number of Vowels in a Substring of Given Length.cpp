/* Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length  */
//code
class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' ||ch=='o' || ch=='u')return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        int ans = 0;
        for(int i = 0; i<k; i++){
            if(isVowel(s[i]) )count++;
        }
        ans = count;
        for(int i = k; i<s.size(); i++){
            if(isVowel(s[i]))count++;
            if(isVowel(s[i-k]))count--;
            ans = max(ans,count);
        }
        return ans;
    }
};
