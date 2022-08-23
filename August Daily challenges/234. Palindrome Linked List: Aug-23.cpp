/* Given the head of a singly linked list, return true if it is a palindrome.

Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 
Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9 */

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
class Solution {
public:
    // Function to reverse a linked list
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL)return head;
        ListNode* curr = head;
        ListNode* nextptr;
        ListNode* prev = NULL;
        while(curr!=NULL){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            
            
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // empty or single node is a palindrome
        if(head==NULL || head->next==NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow pointer points to the middle element
        // reverse the half of linked list
        ListNode* reversedNode = slow->next;
        slow->next = NULL;
        ListNode* newHead = reverse(reversedNode);
        ListNode* temp = head;
        ListNode* temp1 = newHead;
        // iterate in both halfs and check if it is a palindrome or not
        while(temp!=NULL && temp1!=NULL){
            if(temp->val != temp1->val)return false;
            temp = temp->next;
            temp1 = temp1->next;
        }
        return true;
    }
};
