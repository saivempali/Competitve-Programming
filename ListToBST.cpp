/*

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head == NULL)
            return NULL;
            
        ListNode *r1 = head, *r2 = head;
        TreeNode* root;
        
        while(r2 != NULL && r2->next != NULL)
        {
            r1 = r1->next;
            r2 = r2->next->next;
        }
        root = new TreeNode(r1->val);
        root->val = r1->val;
        
        ListNode* Left = NULL,*temp=NULL,*temp2 = head;
        
       
        while(temp2 != r1)
        {
            
            if(temp == NULL)
            {
                temp = new ListNode(temp2->val);
                temp->val = temp2->val;
                Left = temp;
                temp->next = NULL;
                temp2 = temp2->next;
            }
            else
            {
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
                temp->val = temp2->val;
                temp->next = NULL;
                temp2 = temp2->next;
            }
        }
        
        root->left = sortedListToBST(Left);
        
        ListNode* Right=NULL;
        temp = NULL;
        temp2 = r1->next;
        
        while(temp2 != NULL)
        {
            if(temp == NULL)
            {
                temp = new ListNode(temp2->val);
                temp->val = temp2->val;
                Right = temp;
                temp->next = NULL;
                temp2 = temp2->next;
            }
            else
            {
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
                temp->val = temp2->val;
                temp->next = NULL;
                temp2 = temp2->next;
            }
        }
        
        root->right = sortedListToBST(Right);
        
        return root;
    }
};