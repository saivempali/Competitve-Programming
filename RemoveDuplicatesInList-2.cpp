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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
            
        map<int,int> m;
        
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(m.find(temp->val)==m.end())
            {
                m.insert(pair<int,int>(temp->val,1));
            }
            
            else
            {
                m.find(temp->val)->second++;
            }
            
            temp = temp->next;
        }
        
        map<int,int>::iterator it;
        
        ListNode* res = NULL;
        ListNode* newhead;
        for(it = m.begin(); it!=m.end();it++)
        {
            if(it->second == 1)
            {
                if(res == NULL)
                {
                    res = new ListNode(it->first);
                    res->val = it->first;
                    res->next = NULL;
                    newhead = res;
                }
                
                else
                {
                    res->next = new ListNode(it->first);
                    res = res->next;
                    res->val = it->first;
                    res->next = NULL;
                }
            }
        }
        
        return newhead;
    }
};