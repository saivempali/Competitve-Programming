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
    bool hasCycle(ListNode *head) {
        
        
        map<ListNode*,int> m;
        
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            if(m.find(temp) == m.end())
            {
                m.insert(pair<ListNode*,int>(temp,1));
            }
            else
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};