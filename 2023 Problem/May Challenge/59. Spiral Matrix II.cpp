/* Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 
Constraints:

1 <= n <= 20 */
//code
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 0;
        int total = n*n;
        int num = 1;
        int strow = 0, endrow = n-1;
        int stcol = 0, endcol = n-1;
        vector<vector<int>>mat(n, vector<int>(n));

        while(count<total){
            for(int i = stcol; i<=endcol; i++){
                mat[strow][i] = num;
                num++;
                count++;
            }
            strow++;

            for(int i = strow; i<=endrow; i++){
                mat[i][endcol] = num;
                num++;
                count++;
            }
            endcol--;

            for(int i = endcol; i>=stcol; i--){
                mat[endrow][i] = num;
                num++;
                count++;
            }
            endrow--;

            for(int i = endrow; i>=strow; i--){
                mat[i][stcol] = num;
                num++;
                count++;
            }
            stcol++;
        }
        return mat;

    }
};
