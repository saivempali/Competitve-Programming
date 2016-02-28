/*

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

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


    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL ||  headB == NULL)
            return NULL;
            
        ListNode* runnerA = headA;
        int lenA = 0;
        while(runnerA != NULL)
        {
            lenA++;
            runnerA = runnerA->next;
        }
        
        ListNode* runnerB = headB;
        int lenB = 0;
        while(runnerB != NULL)
        {
            lenB++;
            runnerB = runnerB->next;
        }
        
        int diff = 0;
        runnerA = headA;
        runnerB = headB;
        if(lenA <= lenB)
        {
            diff = lenB - lenA;
            for(int i=0; i<diff; i++)
                runnerB = runnerB->next;
        }
        else if(lenA > lenB)
        {
            diff = lenA - lenB;
            for(int i=0; i<diff; i++)
                runnerA = runnerA->next;
        }
        
        while(runnerA != runnerB)
        {
            runnerA = runnerA->next;
            runnerB = runnerB->next;
        }
        
        return runnerA;
    }
};