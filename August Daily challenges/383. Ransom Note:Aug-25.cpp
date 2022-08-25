/* Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters. */

//code
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        // storing the characters of magazine with their frequency in the map
        for(int i = 0; i<magazine.size(); i++){
            mp[magazine[i]]++;
        }
        
        for(int i = 0; i<ransomNote.size(); i++){
            if(mp.find(ransomNote[i])!=mp.end()){
                mp[ransomNote[i]]--;
                
                if(mp[ransomNote[i]] == 0)mp.erase(ransomNote[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};
