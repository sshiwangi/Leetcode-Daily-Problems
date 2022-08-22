/* Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1 */

class Solution { 
public:
    bool isPowerOfFour(int n) {
        // base case
        // if(n == 0) return false;
        // if(n == 1) return true;
        //  check if the remainder is 0 or not when divided by 4 and make recursive calls
        // return (n%4 == 0) && (isPowerOfFour(n/4));
        
        return (n>0) && (n & (n-1)) == 0 && (n & 0x55555555);
//For the number to be divisible by 4,

/*it should be positive (checked by "num > 0")
it should have a single set bit (checked by " ! (num & (num - 1))")
it's set bit should be at an odd position (checked by "(num & 0x55555555)")
P.S: 0x55555555 is a 32 bit integer with all the odd bits set to 1, whereas 0xAAAAAAAA is a 32 bit integer with all the even bits set to 1. */
        
        
    }
    
};
