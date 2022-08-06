/* Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000 */

//code
class Solution {
public:
    // Tabulation approach
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1); // create a 1D dp
        dp[0] = 1; // the possible combinations are 1 if target is 0, which is empty set
        
        for(int i = 1; i<=target; i++){ // traversing across target
            for(int j = 0; j<nums.size(); j++){ // traversing across nums array
                if(nums[j] <= i){
                    dp[i] += dp[i - nums[j]];
                }
           }
        }
        return dp[target];
    }
};
