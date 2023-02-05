/* Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters. */

//code
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>hash1(26,0), hash2(26,0);
        for(int i = 0; i<s1.size(); i++){
            hash1[s1[i]-'a']++; // put all the characters of s1 in hash1
        }
        int i = 0, j = 0;
        while(j<s2.size()){ // iterate in the s2
            hash2[s2[j]-'a']++; // and keep adding character in another hash2
            if(j>=s1.size()){ // if j exceeds the window size, we have to remove the character at ith index from the hash2
                hash2[s2[i]-'a']--;
                i++;
            }
            if(hash1 == hash2)return true; // if hash1 is same as hash 2 then reutrn true
            j++;
        }
        return false; // if there is no permutation of s1 found in s2, then return false
    }
};
