/*Problem Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, 
construct and return the binary tree.

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.*/

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
    TreeNode* constructTree(int inSt, int inEnd,vector<int>& inorder, int postSt, int postEnd, vector<int>& postorder, unordered_map<int,int>&mp){
        if(inSt>inEnd || postSt>postEnd)return NULL; //for invalid case
        TreeNode* root = new TreeNode(postorder[postEnd]); //our tree's root will be the last value of postorder vector
        int rootPos = mp[root->val]; //finding root's position in inorder vector
        int leftSubLen = rootPos-inSt; //length of leftsubtree
        //constructing left subtree
        root->left =  constructTree(inSt,rootPos-1,inorder,postSt,postSt+leftSubLen-1,postorder,mp);
        //constructing right subtree
        root->right = constructTree(rootPos+1,inEnd,inorder,postSt+leftSubLen,postEnd-1,postorder,mp); 
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int m = postorder.size();
        //inorder to reduce time complexity for finding the root's position in inorder vector, we will store all the values of inorder traversal in a map
        unordered_map<int,int>mp; 
        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }
        //Defining subtree's starting and ending position in both the array
        int inSt = 0, inEnd = n-1, postSt = 0, postEnd = m-1;
        return constructTree(inSt,inEnd,inorder,postSt,postEnd, postorder,mp);
    }
};
