/* Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space. */

// Bijection means each element of a set is mapped with exactly one element of another set and each element of the other set has exactly one paired partner in the first set.
//code
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        string temp = "";
        // storing the words of string s in the vector to get rid of the spaces
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp+=s[i];
            }
        }
        v.push_back(temp); // pushing last word to the vector
        if(v.size()!=pattern.size())return false; // if the sizes are not same then there will never be a case when they can be fully matched.

        unordered_map<char,string>mp; 
        set<string>st;

        for(int i = 0; i<pattern.size(); i++){
            if(mp.find(pattern[i])!=mp.end()){ // if the char is already mapped with some word
                if(mp[pattern[i]]!=v[i])return false;// and if the same char is mapped with another word then return false.
            }
            else{ // if the char is not present in the map i.e it is not mapped with any word, then we have to map it to the word but making sure that the word we are mapping to is not already mapped with any other character that's why we will check if it is present in set or not.
                if(st.count(v[i])>0)return false;
                // else we can do the mapping
                mp[pattern[i]] = v[i];
                st.insert(v[i]);
            }
        }
        return true;

    }
};
