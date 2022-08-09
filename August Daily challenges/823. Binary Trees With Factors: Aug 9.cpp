/* Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. 
Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 109
All the values of arr are unique.
*/
//code
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        // sort the array so that we don't have to do extra work checking larger numbers than the array element.
        sort(arr.begin(),arr.end());
        long mod = 1e9 + 7;
        // map stores the count of trees formed using the elements
        unordered_map<int,long> mp;
        mp[arr[0]] = 1; // since we can only create 1 binary tree using the smallest element, start iterating form the 2nd element of array.
        
        for(int i = 1; i<arr.size(); i++){
            long count = 1; // all elemets can give atleast 1 bt so count = 1
            
            for(auto it: mp){
                int ele = it.first;
                // if arr[i]%ele == 0, there is a possibility we can make another tree using arr[i]. also if we found the number in the map which on multiplying with ele, gives the arr[i], we will add freq of ele * freq of that element in the count.
                if(arr[i] % ele == 0 && mp.find(arr[i]/ele)!= mp.end()){
                    count += mp[ele] * mp[arr[i]/ele];
                }
            }
            // and update the value of arr[i] in the map with the new count of trees.
            mp[arr[i]] = count;
        }
        int ans = 0;
        for(auto it: mp){
            ans = (ans + it.second) % mod;
        }
        return ans;
    }
};
