/* https://leetcode.com/problems/verifying-an-alien-dictionary/description/
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters. */

//code
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
       unordered_map<char,int>mp;
       for(int i = 0; i<order.size(); i++) {
           mp[order[i]] = i;
       }
       
       for(int i = 0; i<words.size()-1; i++){
           int j = 0;
            while(j<words[i].size() && j<words[i+1].size()){
                // if the words pair are sorted then we will move to the next pair
                if(mp[words[i][j]] < mp[words[i+1][j]])break;
                // if they are placed in incorrect order, return false
                else if(mp[words[i][j]] > mp[words[i+1][j]]){
                    return false;
                   
                }
                j++;
            }
            if(j == words[i+1].size() && j <words[i].size())return false;  // if the first string of the pair's length is greater than the second one, then it should return false  
            
        }
       
       return true;
    }
};
