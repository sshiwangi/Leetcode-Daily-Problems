/* Problem link: https://leetcode.com/problems/break-a-palindrome/
Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter 
so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, 
a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" 
because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.
Example 2:

Input: palindrome = "a"
Output: ""
Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.
 

Constraints:

1 <= palindrome.length <= 1000
palindrome consists of only lowercase English letters. */

//code
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1)return ""; // if their is only one character in the string it is always palindrome
        for(int i = 0; i< n/2; i++){ // we will go to the half of string and check if the char is greater than a or not, if yes, replace it with a as it is the smallest char and return palindrome
            // Ex: palindrome: abccba
            // possible answers are: bbccba, aaccba, abacba
            // we can see that aaccba is the lexicographically smallest that is we need to replace the first character that is greater than 'a'
            if(palindrome[i]>'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
            
        }
        palindrome[n-1] = 'b'; // if we didn't get any char greater than a in the half of the string, replace it with b as it will be the lexicographicaly smallest among all possible strings.
        //EX: palindrome = aaaa
        // possible strings are: baaa, abaa, aaba, aaab 
        // so we can see that the string where b is at last position is lexicographicaly smallest
        return palindrome;
        
    }
};
