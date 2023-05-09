/* Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100 */

//code
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int strow = 0, stcol = 0;
        int endrow = m-1, endcol = n-1;
        int count = 0;
        int total = m*n;

        while(count<total){
            //traversing right
            for(int i = stcol; count<total && i<=endcol; i++){
                ans.push_back(matrix[strow][i]);
                count++;
            }
            strow++;

            //traversing downward
            for(int i = strow; count<total && i<=endrow; i++){
                ans.push_back(matrix[i][endcol]);
                count++; 
            }
            endcol--;

            //traversing left
            for(int i = endcol; count<total && i>=stcol; i--){
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;

            //traversing upwards
            for(int i = endrow; count<total && i>=strow; i--){
                ans.push_back(matrix[i][stcol]);
                count++;
            }
            stcol++;
        }
        
        return ans;
    }
};
