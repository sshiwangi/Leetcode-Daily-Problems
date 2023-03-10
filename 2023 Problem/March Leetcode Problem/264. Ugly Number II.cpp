/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690 */
//code
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1; //first ugly number will be 1
        //initially the pointers will point to the first number that is 1
        int p1 = 0; 
        int p2 = 0; 
        int p3 = 0;

        for(int i = 1; i<n; i++){
            //to find out the next choices of ugly number, we will multiply all three numbers with the number at which their pointer is pointing
            int twomultiple = dp[p1]*2; 
            int threemultiple = dp[p2]*3;
            int fivemultiple = dp[p3]*5;

            dp[i] = min(twomultiple, min(threemultiple, fivemultiple)); // the next ugly number will be the minimum among them

            if(dp[i] == twomultiple)p1++; //increment the pointers if the ugly number is its multiple
            if(dp[i] == threemultiple)p2++;
            if(dp[i] == fivemultiple)p3++;
        }
        return dp[n-1];
    }
};
