/* You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.

Example 1:

Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.
Example 2:

Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
Example 3:

Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players. 
 

Constraints:

1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 106
1 <= ages[i] <= 1000 */

//code
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int,int>>v; //vector to store pair of age and scores
        for(int i = 0; i<n; i++){
            v.push_back({ages[i],scores[i]}); // pushing age first because we want to sort it based on ages as in this way we don't have to compare ages again and again
        }
        sort(v.begin(),v.end()); // sort the vector
        vector<int>dp(n+1); 
        dp[0] = v[0].second; // put the score of first player in the array
        for(int i = 1; i<n; i++){ // and start iterating from the second so that we can compare each index with its previous ones
            dp[i] = v[i].second;
            for(int j = 0; j<i; j++){ // this loop will check all the previous player's scores till i
                if(v[i].second >= v[j].second){ // if the current player's score is greater or equal than the younger ones
                    dp[i] = max(dp[j] + v[i].second, dp[i]);// then we will consider it in our answer
                }
            }
        }
        return *max_element(dp.begin(),dp.end()); // return the max element from the dp vector
    }
};
