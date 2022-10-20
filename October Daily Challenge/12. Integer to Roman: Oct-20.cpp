/* Problem link: https://leetcode.com/problems/integer-to-roman/
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999 */

//code
class Solution {
public:
    // first write all the numbers whose roman values is none. Then start checking the range in which the numbers lie but start with the greater one.
    /* 
    EX: num = 3476
         we see num is greater than 1000, so append M in the ans and substract 1000 from the num
         Now, num = 3476-1000 = 2476, it's still greater than 1000, so do the same until it's greater than 1000.
         ans = MMM
         
        Now, num = 476, we can see it's greater than 400 and less than 500 but since it is not 500 or more we can't use D here. so, we will append CD to the answer and the number becomes: 476-400 = 76
        ans = MMMCD
        we will keep doing this and we realise that the numerals which had to repeat itself are M,C,X AND I*/
    
    string intToRoman(int num) {
        string ans = "";
        while(num >= 1000){
            ans += "M";
            num -= 1000;
        }
        if(num >= 900){
            ans += "CM";
            num -= 900;
        }
        if(num >= 500){
            ans += "D";
            num -= 500;
        }
        if(num >= 400){
            ans += "CD";
            num -= 400;
        }
        while(num >= 100){
            ans += "C";
            num -= 100;
        }
        if(num >= 90){
            ans += "XC";
            num -= 90;
        }
        if(num >= 50){
            ans += "L";
            num -= 50;
        }
        if(num >= 40){
            ans += "XL";
            num -= 40;
        }
        while(num >= 10){
            ans += "X";
            num -= 10;
        }
        if(num >= 9){
            ans += "IX";
            num -= 9;
        }
        if(num >= 5){
            ans += "V";
            num -= 5;
        }
        if(num >= 4){
            ans += "IV";
            num -= 4;
        }
        while(num >= 1){
            ans += "I";
            num -= 1;
        }
        return ans;
       
    }
};
