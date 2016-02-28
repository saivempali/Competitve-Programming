/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        stack<int> mystack;
        ListNode* runner = head;
        for(int i=1; i<m; i++){
            runner = runner->next;
        }
        
        for(int i=m; i<=n; i++){
            mystack.push(runner->val);
            runner = runner->next;
        }
        
        runner = head;
         for(int i=1; i<m; i++){
            runner = runner->next;
        }
        
        for(int i=m; i<=n; i++){
            runner->val = mystack.top();
            mystack.pop();
            runner = runner->next;
        }
        
        return head;
    }
};