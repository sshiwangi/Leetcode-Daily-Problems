/* You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. 
You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. 
More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

Example 1:

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
Example 2:

Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.
Example 3:

Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
 

Constraints:

2 <= properties.length <= 105
properties[i].length == 2
1 <= attacki, defensei <= 105 */

//code
class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1] > b[1]; // the char with greater defense value will be written first in case of same attack values
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // sort the vector with respect to the attack values
        sort(properties.begin(),properties.end(),comp);
        // [[3,6],[5,5],[6,3]]
        int ans = 0;
        int maxDef = INT_MIN;
        
        //start iterating from back because the characters on the left has attack values either less or equal to the current one. so all the characters on the left side of [6,3] can be our answer only if their defense value is lesser than that of the current char.
        
         /*Everytime we find any such element we will increment ans and we will keep updating maxdef whenever the defense value becomes greater than the current one. */
        
        for(int i = properties.size()-1; i>=0; i--){ 
            if(properties[i][1]>maxDef){
                maxDef = properties[i][1];
            }
            else if(properties[i][1]<maxDef){
                ans++;
            }
        }
        return ans;

        
    }
};
