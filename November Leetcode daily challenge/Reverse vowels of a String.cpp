/* Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 
Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters. */

//code

class Solution {
public:
    string reverseVowels(string s) {
        stack<int>st;
        for(int i = 0; i<s.size(); i++){
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') || (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')){
                st.push(s[i]); // if it is a vowel push it in stack
            }
        }
        for(int i = 0; i<s.size(); i++){
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') || (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')){
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};
