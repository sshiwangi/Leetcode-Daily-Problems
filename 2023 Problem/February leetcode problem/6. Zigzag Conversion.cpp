/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000 */

//code
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>v(numRows); // a vector to store the pattern
        if(numRows == 1)return s; // if there is only one row that will be our answer
        bool flag = false; 
        int i = 0;
        for(auto ch: s){ // iterate in the given string
            v[i]+=ch; // store the first character in the 0th index of the vector
            if(i==0 || i == numRows-1){ // whenever our i becomes 0 or 2, we have to flip flag
                flag = !flag;
            }
            if(flag){ // if flag's value is true, move downwards
                i+=1;
            }
            else{ // otherwise move upwards
                i-=1;
            }
        }
        string ans = ""; // string to store answer
        for(auto str:v){
            ans += str;
        }
        return ans; // return ans
    }
};
