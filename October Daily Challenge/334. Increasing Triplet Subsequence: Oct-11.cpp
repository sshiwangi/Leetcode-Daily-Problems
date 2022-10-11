/* Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, 
return false.

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1 */

//code
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return false;
        // we will maintain two variables and update them according to the given condition:
        //1. if we found any element lesser than left, update left.
        // 2. if we found any element greater than left, update mid
        // till now we figured out two elements that follows the criteria of the problem, now we need a number greater than mid, to form triplet subsequence. so as we find any number greater than mid, we will return true;
        int left = INT_MAX;
        int mid = INT_MAX;
        for(int i = 0; i<n; i++){
            if(nums[i]>mid)return true;
            else if(nums[i]>left && nums[i]<mid)mid = nums[i];
            else if(nums[i]<left)left = nums[i];
        }
        return false;
    }
};
