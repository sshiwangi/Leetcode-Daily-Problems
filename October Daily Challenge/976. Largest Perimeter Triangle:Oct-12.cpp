/* Problem link:https://leetcode.com/problems/largest-perimeter-triangle/
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. 
If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:

Input: nums = [2,1,2]
Output: 5
Example 2:

Input: nums = [1,2,1]
Output: 0
 

Constraints:

3 <= nums.length <= 104
1 <= nums[i] <= 106 */

//code
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans;
        
        for(int i =0; i<nums.size()-2; i++){
            if(nums[i]< nums[i+1] + nums[i+2]){ // if at any point we come across two elements that is greater than third element we can form a triangle and since the array is sorted we can simply return the first found triangle perimeter as it will be the largest.
                ans = nums[i] + nums[i+1] + nums[i+2]; 
                return ans;
            }
        }
        return 0;
    }
};
