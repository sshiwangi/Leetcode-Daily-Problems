/* You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
Constraints:

2 <= arr.length <= 105
arr.length is even.
1 <= arr[i] <= 105 */

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // arr: [3,3,3,3,5,5,5,2,2,7]
        map<int,int> mp; // this map stores elements in increasing order with respect to the key.
        
        for(auto it: arr){
            mp[it]++;
        }
     /*   arr[i], freq
          mp = {2-2
                3-4
                5-3
                7-1} */
        // but we want the map to be sorted in the decreasing order so that we will chose most occuring number first.
        // so we will use multimap and put freq first and then key in it.
        
        multimap<int,int, greater<int>> mm;
        for(auto it: mp){
            mm.insert({it.second,it.first});
        }
        /*    freq, arr[i]
         mm =   {4-3
                 3-5
                 2-2
                 1-7} */
        
        int n = arr.size();
        int sum = n;
        int count = 0; // stores the count of minimum element we will chose such that the array is reduced to atleast half
        
        for(auto it=mm.begin(); it!=mm.end(); it++){
            sum -= it.first;
            count++;
            if(sum<=n/2)return count;
        }
    
        return count;

	// unordered_map<int, int> umap;
	// for(auto i: arr)
	// 	umap[i]++;
	// priority_queue<pair<int,int>> pq;
	// for(auto i: umap){
	// 	pq.push({i.second, i.first});
	// }
	// int cnt=0, sz=0;
	// while(!pq.empty()){
	// 	// cout << pq.top().first << " " << pq.top().second;
	// 	int f = pq.top().first, s = pq.top().second;
	// 	cnt++;  sz+=f;
	// 	if(sz>=arr.size()/2)  return cnt;
	// 	pq.pop();
	// }
	// return cnt;
	

    }
};
