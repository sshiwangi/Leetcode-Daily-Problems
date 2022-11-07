/* You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
 
Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits. */

//code

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        int i = 0;
        int ans = 0;
        while(i<s.size()){
            if(s[i] == '6'){ // if the first digit is 6, convert it into 9 and return the num as it will be the maximum number
                s[i] = '9';
                break;
            }
            else{
                i++; // if it is 9, check for other digits
            }
            
        }
        //converting the string back to integer
        ans = stoi(s);
        return ans;
    }
};
