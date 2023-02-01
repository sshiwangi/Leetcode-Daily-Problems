/* https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters. */
//code
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // if there is a common string in both of them then that means the sum of them in any order will be same. and if there is not a common string that divides both of them then we will return empty string.
        if(str1 + str2 == str2 + str1)return str1.substr(0,gcd(str1.length(),str2.length()));
        return "";
    }
};
