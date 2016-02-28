/*

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
        
        map<ListNode*,int> m;
        
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            if(m.find(temp)==m.end())
            {
                m.insert(pair<ListNode*,int>(temp,1));
            }
            else
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};