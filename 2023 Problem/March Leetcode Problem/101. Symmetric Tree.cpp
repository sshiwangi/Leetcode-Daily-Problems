/* Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false
 
Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 
Follow up: Could you solve it both recursively and iteratively? */
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
    bool solve(TreeNode* leftSub, TreeNode* rightSub){
        if(!leftSub && !rightSub)return true;
        if(!leftSub || !rightSub)return false;
        if(leftSub->val != rightSub->val)return false;
        return solve(leftSub->left, rightSub->right) && solve(leftSub->right, rightSub->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root || !root->left && !root->right){
            return true;
        }
        return solve(root->left,root->right);
    }
};
