/* Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:


Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1 */

/* Intuition
The first thing that comes to our mind is check each cell containing 0 and then do a BFS search and find the nearest cell containing 1 and store the distance in a new distance matrix. But this is the brute force approach as we have to find closest distance of land cells from water cell everytime fround ground up.

Approach
If we think in a reverse manner that is instead of checking all the water, if we check all the land then we can optimize the time complexity.

Steps:

Store each cell containing 1 in a queue.
if the queue is empty meaning if there is no 1s in the grid or if the queue's size is the size of the grid meaning all the cells have 1 and no water is present then according to the question, we will return -1.
Take a variable level and initialize it with -1.
Take out coordinates from the queue and do a bfs traversal and find the next coordinates.
if the next cell is valid and contains a zero then mark it to be 1 and store it's coordinates in the queue as that will be a part of all the water cell that is present at 1 distance from the current one.
This will reduce time complexity as we are taking help from the previously stored distance. */
//code
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>>v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // all four direction
        queue<pair<int,int>>q; // queue to store land
        // traverse in the grid and push all cells containing 1
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid.size(); j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        if(q.empty() || q.size() == n*n){ // if there are no 1s or no 0s in the grid then we will return -1
            return -1;
        }
        int level = -1; // declare level to be -1 as after traversing the first set of 1s, the algo will update it to be 0 as that will be 0th level
        while(!q.empty()){
            int size = q.size();
            while(size){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i<4; i++){ // find coordinates of next cell from the current cell
                    int nx = x + v[i].first;
                    int ny = y + v[i].second;
                    // if the next cell is valid and contains 0 then mark it to be 1 and push it in the queue, this will be a part of all those zeros that are at 1 distance from 1s.
                    if(nx>=0 && nx<grid.size() && ny >=0 && ny<grid.size() && grid[nx][ny] == 0){
                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                size--;
            }
            level++;// increment the level
        }
        return level; // when the queue will be empty, the last level elements will be the farthest distance and it will be our answer therefore return level.
    }
};
