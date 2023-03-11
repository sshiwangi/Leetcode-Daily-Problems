/* Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.
 
Example 1:

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 
Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105 */

//code
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildTree(vector<int>&inorder, int start, int end){
        if(start>end)return NULL;//invalid tree
        int rootIdx = (start + end)/2; //finding index of root.
        TreeNode* root = new TreeNode(inorder[rootIdx]); //creating root of  bst
        if(start == end)return root; //if there is only one element, return root
        root->left = buildTree(inorder,start,rootIdx-1); //build the left subtree
        root->right = buildTree(inorder,rootIdx+1, end); //build the right subtree
        return root;//return root
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        vector<int>inorder;
        //storing the nodes of linked list in inorder vector
        while(temp!=NULL){
            inorder.push_back(temp->val);
            temp= temp->next;
        }
        int n = inorder.size();
        TreeNode* root = buildTree(inorder, 0, n-1);
        return root;
    }
};
