/* Problem link: https://leetcode.com/problems/can-place-flowers/description/
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can 
be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 
Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length */
//code

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)return true;
        int m = flowerbed.size();
        bool ans = false;
        if(m==1){
            if(flowerbed[0]==0)return true;
            else return false;
        }
        if(flowerbed[0] == 0){
            if(flowerbed[1]==0){
                flowerbed[0] = 1;
                n = n-1;
                if(n==0){
                    ans = true;
                    return ans;
                }
            }
        }
        for(int i = 1; i<m-1; i++){
            if(flowerbed[i]==0){
                if(flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                    flowerbed[i] = 1;
                    n = n-1;
                    if(n==0){
                        ans = true;
                        break;
                    }
                    
                }
                else continue;
            }
            else continue;
        }
        
        if(flowerbed[m-1] == 0){
            if(flowerbed[m-2]==0){
                flowerbed[m-1] = 1;
                n = n-1;
                if(n==0)ans = true;
                return ans;
            }
        }
        if(ans)return true;
        else return false;

    }
};
