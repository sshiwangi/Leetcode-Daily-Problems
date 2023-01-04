/* You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

Example 1:

Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
Example 2:

Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.
 

Constraints:

1 <= tasks.length <= 105
1 <= tasks[i] <= 109 */

// For detailed explaination : https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/solutions/2995189/easiest-c-solution-with-detailed-explanation/
//code
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int i = 0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        int ans = 0;
        for(auto it: mp){
            if(it.second == 1)return -1; // if the frequency is less than 2, return -1
            else if(it.second%3==0){ // if it is divided by 3, just return the freq/3 which is the number of rounds to complete the taks
                ans += it.second/3;
            }
            else{ // else there will be two cases, either remainder will be 2 or remainder will be 1, in both the cases add 1 to freq/3.
                ans += it.second/3 + 1;
            }
        }
        return ans;
    }
};
