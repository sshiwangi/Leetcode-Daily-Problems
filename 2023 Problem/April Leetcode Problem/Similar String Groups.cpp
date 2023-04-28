/* Problem Link: https://leetcode.com/problems/similar-string-groups/description/
Solution link: https://leetcode.com/problems/similar-string-groups/solutions/3464251/easy-c-solution-with-comments-dfs/

Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1
 

Constraints:

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other. */

//code
class Solution {
public:
//checking the strings are similar or not.
    bool isSimilar(string a, string b){
        int diff = 0; //a/q to question two strings are similar only when they are exact same or differ at exactly two positions
        for(int i= 0; i<a.length(); i++){
            if(a[i]!=b[i])diff++;
        }
        if(diff==2 || diff == 0)return true;
        else return false;
    }
    //simple dfs traversal
    void dfs(int i, vector<string>& strs, vector<int>&vis){
        vis[i] = 1;
        for(int j = 0; j<strs.size(); j++){
            if(!vis[j] && isSimilar(strs[i], strs[j])){ //if jth string is the neighbour
                dfs(j, strs, vis);//then we will check the neighbour of jth string that whether it is similar of not
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int count = 0; //for counting the number of connected components that is our answer
        int n = strs.size();
        vector<int>vis(n,0); //visited array
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i,strs,vis);
                count++;
            }
        }
        return count;
    }
};
