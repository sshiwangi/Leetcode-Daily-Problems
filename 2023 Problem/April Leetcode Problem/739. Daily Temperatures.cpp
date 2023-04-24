/* Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100 */

//code
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int>ans(n,0); //initializing the ans vector with 0
      stack<int>st; //stack to store the indices of the temperatures items
      //since we have to find out next warmer temperature, we will iterate from the end
      for(int i = n-1; i>=0; i--){
        while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
          // we will pop out the elements
          st.pop();
        }
        // if we found a greater element to the right and if the stack is not empty then we will calculate the distance of the current element from the next greater element and put in the ans vector
        if(!st.empty()){
          ans[i] = st.top() - i;
        }
        st.push(i);//pushing the index of element in the stack
      }
        return ans;
    }
};
