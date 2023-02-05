/* Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters. */

//code
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>mp(26,0), mp1(26,0);
        for(int i = 0; i<p.size(); i++){
            mp[p[i]-'a']++; //storing the character of string p with its count in mp
        }
        int i = 0, j = 0;
        vector<int>ans;
        while(j<s.size()){ 
            mp1[s[j]-'a']++;
            if(j>=p.size()){ // if the size becomes greater than the size of window
                mp1[s[i]-'a']--;
                i++;

            }
            if(mp == mp1)ans.push_back(i); // if both arrays are equal, push the value of i in the array as it will be the starting index of anagram.
            j++;
        }
        return ans;
    }
};
