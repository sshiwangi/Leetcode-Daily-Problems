/* Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 
Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters. */

//code
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for(int i = 0; i<word1.size(); i++){
            str1 += word1[i];
        }
        for(int i = 0; i<word2.size(); i++){
            str2 += word2[i];
        }
        if(str1 == str2)return true;
        return false;
    }
};

//or
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        int wordIdx1 = 0, wordIdx2 = 0, chIdx1 = 0, chIdx2 = 0;
        while(true)
        {
            char ch1 = word1[wordIdx1][chIdx1];
            char ch2 = word2[wordIdx2][chIdx2];
            if (ch1 != ch2) return false;
            
            chIdx1++; //incrementing the character index of current word from "word1"
            chIdx2++; //incrementing the character index of current word from "word2";
            //=========================================================
            if (chIdx1 == word1[wordIdx1].size()) //if current word from "word1" is over
            { 
                wordIdx1++;  //move to next word in "word1"
                chIdx1 = 0;  //reset character index to 0
            }
            if (chIdx2 == word2[wordIdx2].size()) //if  current word from "word2" is over
            { 
                wordIdx2++;  //move to next word  in "word2"
                chIdx2 = 0; //reset character index to 0
            }
            //=================================================================
            if (wordIdx1 == word1.size() && wordIdx2 == word2.size()) break; // words in both arrays are finished
            
            if (wordIdx1 == word1.size() || wordIdx2 == word2.size()) return false;
            //if words in any onr of the arrays are finished and other still has some words in it
            //then there is no way same string could be formed on concatenation
        }
        return true; 
    }
};
