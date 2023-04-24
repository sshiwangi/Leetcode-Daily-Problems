/* You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Example 1:

Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:

Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0
 
Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100 */
//code
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:     
    int ans = 0;
    void solve(TreeNode* node, bool dir, int len) {
        //dir = true (right)
        //dir = false (left)
        if (!node) return;
        ans = max(ans, len);
        if (dir) {//if the parent is coming from right
            solve(node->left, false, len + 1); //we need to go to the left and since it will be considered as a zig-zag path, we will add 1 to the current length
            solve(node->right, true, 1); //otherwise not
        } else { //if the parent is coming from left,
            solve(node->right, true, len + 1); //go to the right
            solve(node->left, false, 1);//if both parent and child are coming from left, then it will be considered as a new zig-zag path
        }
    }

    int longestZigZag(TreeNode* root) {
        solve(root, true, 0); //we will assume that root is coming from both left and right direction
        solve(root, false, 0);
        return ans;
    }
        
    
};
