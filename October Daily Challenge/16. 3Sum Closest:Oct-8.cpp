/* Problem link: https://leetcode.com/problems/3sum-closest/
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104 */

//code

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans;
        int diff = INT_MAX; 
        
        for(int i = 0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == target)return target;
                else if(abs(sum - target)<diff){ //if we found 3 numbers whose difference of sum and target is lesser than the diff, update the diff with new smaller difference.
                    diff = abs(sum-target);
                    ans = sum; // update the ans
                }
                if(sum<target)j++; // inorder to come closer to the target, the sum needs to increase in this case so increment j pointer
                if(sum>target)k--;
            }
        }
        return ans;
    }
};
