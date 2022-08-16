/* Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters. */

//code
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX;
        unordered_map<char,int> freq_mp;
        unordered_map<char,int> idx_mp;
        
        for(int i = 0; i<s.size(); i++){
            // storing all characters with their frequency in the freq map
            freq_mp[s[i]]++;
            // if the char occurs once, then store it in idx map along with its index
            if(freq_mp[s[i]]==1){
                idx_mp[s[i]] = i;
            }
            // if it occurs more than once, check if we have inserted this char in idx map and delete it.
            else{
                if(idx_mp.find(s[i])!=idx_mp.end()){
                    idx_mp.erase(s[i]);
                }
            }
        }
        // if there is no unique character, return -1
        if(idx_mp.size()==0){
            return -1;
        }
        // otherwise traverse in the idx map, and find the minm idx and return it.
        else{
            for(auto it: idx_mp){
                ans = min(ans,it.second);
            }
            return ans;
        }
    }
};
