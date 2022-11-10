/* You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters. */

//code
class Solution {
public:
    string removeDuplicates(string s) {
      // 1st method
      
        // stack<char> st;
        // for(int i = 0; i<s.size(); i++){
        //     if(st.empty()){
        //         st.push(s[i]);
        //         continue;
        //     }
        //     else if(st.top() == s[i])st.pop();
        //     else st.push(s[i]);
        // }
        // string ans = "";
        // while(!st.empty()){
        //     ans = st.top() + ans;
        //     st.pop();
        // }
        // return ans;
      
      // 2nd method
        string ans;
        for(int i = 0; i<s.size(); i++){
            if(ans.size() && ans.back() == s[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
