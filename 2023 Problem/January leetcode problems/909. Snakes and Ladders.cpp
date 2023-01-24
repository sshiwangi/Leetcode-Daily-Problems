/* https://leetcode.com/problems/snakes-and-ladders/description/
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

Example 1:


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1
 

Constraints:

n == board.length == board[i].length
2 <= n <= 20
grid[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 do not have any ladders or snakes. */
//code
class Solution {
public:
   // Finding coordinates of the element at position curr on the board
    vector<int> findCordinates(int curr, int n){
        int r = n - (curr - 1)/n -1; // for row
        int c = (curr - 1)%n; // for column
        if(r%2 == n%2){ // if both row and n is even
            return {r, n-1-c}; 
        }
        else{
            return {r, c};
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int>q;
        int steps = 0; // counts the steps
        vector<vector<bool>> vis(n, vector<bool>(n, false)); // visited array marked with 0
        q.push(1); 
        vis[n-1][0] = true;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                int ele = q.front();
                q.pop();
                if(ele == n*n)return steps; // if we reach the n*n box, return the steps

                for(int k = 1; k<=6; k++){ // the all 6 numbers on dice
                    if(ele + k > n*n)break;
                    vector<int>pos = findCordinates(ele + k, n);
                    int r = pos[0];
                    int c = pos[1];
                    if(vis[r][c] == false){
                       vis[r][c] = true;
                       if(board[r][c] == -1){ // if it is a regular box
                           q.push(ele + k);
                        }
                        else{
                           q.push(board[r][c]); // if it is snake or ladder
                        }
                    }
                    
                }
            }
            steps++;
        }
        return -1;
    }
};
