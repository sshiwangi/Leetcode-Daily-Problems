/* Problem Link: https://leetcode.com/problems/koko-eating-bananas/description/
Solution Link: https://leetcode.com/problems/koko-eating-bananas/solutions/3273055/well-commented-solution-using-binary-search-with-intuition-and-approach/

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 
Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109 */

//code
class Solution {
public:
    bool isValid(vector<int>& piles, int mid, int h){ //function to check if at mid value, koko can finish all the bananas within h hours r not.
        int count = 0; // for counting hours each time koko chooses a pile.
        for(auto i: piles){ //iterate in array
            count += i/mid; // adding total hours taken to finish the bananas of the current piles 
            if(i%mid!=0)count++; // if Koko will be needing another hour to finish the banans
        }
        if(count<=h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1, end = *max_element(piles.begin(), piles.end());
        int ans = end;
        while(st<end){
            int mid = st + (end - st)/2;
            if(isValid(piles,mid,h)){
                ans = min(ans,mid);
                end = mid;
            }
            else {
                st = mid+1;
            }
        }
        return ans; // return ans
    }
};
