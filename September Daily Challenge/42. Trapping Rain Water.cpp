/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

//code
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // Declaring two arrays to store the maximum height on the left and right side of buiding at ant index
        int mxl[n];
        int mxr[n];
        
        // initialize mxl with the first element of the array
        mxl[0] = height[0];
        // initialize mxr with the last element of the array
        mxr[n-1] = height[n-1];
        
        // traverse in the rest of the array, and fill the mxl array
        for(int i = 1; i<n;i++){
            mxl[i] = max(mxl[i-1],height[i]);
        }
        
        for(int i = n-2; i>=0;i--){
            mxr[i] = max(mxr[i+1],height[i]);
        }
        
        // declaring water array to store the unit of water stored on each building
        int water[n];
        for(int i = 0; i<n; i++){
            water[i] = min(mxl[i],mxr[i]) - height[i];
        }
        // traverse in the water array and add the units of water
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + water[i];
        }
        return sum;
        
    }
};
