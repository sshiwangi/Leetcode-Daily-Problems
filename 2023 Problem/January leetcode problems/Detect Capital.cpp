/* We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters. */

//code
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = true;
        if(word[0] >= 65 && word[0]<=90){// if first character is capital
           if(word[1]>=65 && word[1]<=90){ // if second char is capital then all the char must be capital      
               for(int i = 2; i<word.size(); i++){
                   if(word[i]>=97 && word[i]<=122){ // if any char is small
                       flag = false;
                       break;
                   }
               }
           } 
           else{ // if second char is small then all the char must be small
               for(int i = 2; i<word.size(); i++){
                   if(word[i]>=65 && word[i]<=90){ // if any char is capital
                       flag = false;
                       break;
                   }
               }
           }
        } 
        else{ // if first character is small then the rest of characters must be small
           for(int i = 1; i<word.size(); i++){
               if(word[i]>=65 && word[i]<=90){
                   flag = false;
                   break;
               }
           }
        }
        return flag;
    }
};

// Second Method
/* Intuition: use a counter and isupper function to check number of capital.

Approach:

Initialize count=0
if count equals 0 means all are small chars
if count equals size of word then all are capital
if count equals 1 then check is it the first char which is capital
if none of the conditions are true then return false */
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        if(word.size()==1)
            return true;
        
        for(int i=0; i<word.size(); i++)
            if(isupper(word[i]))
                count++;
        
        if(count==1 && isupper(word[0]))
            return true;
        if(count==0 || count==word.size())
            return true;
        else
            return false;
    }
};
