/* Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters. */

//code
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        while(j<haystack.size()){//traverse in haystack
            if(j-i+1 < needle.size()){ // keep increasing j 
                j++;
            }
            else if(j-i+1 == needle.size()){ // when the size of sub string becomes equal to the size of the needle, we will check if they are equal or not, if equal return i as it is the starting index of the sub string
                if(haystack.substr(i,needle.size()) == needle){
                    return i;
                    
                }
                i++; // if the sub string is not equal, we will move on to the next sub string of the size of the needle and for that we need to increment i.
                j++;
            }    
        }
        return -1;
    }
};
