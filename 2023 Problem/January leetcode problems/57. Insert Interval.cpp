/* Link: https://leetcode.com/problems/insert-interval/description/
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval 
and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals 
(merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105 */
//code
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(auto it: intervals){
            // if newInterval range comes after current interval
            if(it[1]<newInterval[0]){
                ans.push_back(it);
            }
            // if new interval range comes before the current interval then in order to keep it sorted, we have to add the new interval first. so we will push new interval this time.
            else if(it[0]>newInterval[1]){
                ans.push_back(newInterval);
                newInterval = it; //updating the current interval
            }
            // else(that is in the case of overlapping) we will insert min of the start of intervals and newIntervals and maximum of the end of the two intervals
            // Ex: intervals = [[1, 3]], newInterval = [2,5], so we will insert [1,5]
            else{
                newInterval[0] = min(it[0],newInterval[0]);
                newInterval[1] = max(it[1],newInterval[1]);
            }
            
        }
        ans.push_back(newInterval);
        return ans;
    }
};
