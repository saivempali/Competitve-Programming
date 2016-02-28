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
        
        map<int,int> m;
        
        ListNode* temp = head,*prev = NULL;
        
        while(temp != NULL)
        {
            if(m.find(temp->val) == m.end())
            {
                m.insert(pair<int,int>(temp->val,1));
                
                prev = temp;
                temp = temp->next;
            }
            else
            {
                if(temp->next != NULL)
                {
                    temp->val = temp->next->val;
                    temp->next = temp->next->next;
                }
                else
                {
                    prev->next = NULL;
                    temp = temp->next;
                }
            }
        }
        
       
        return head;
    }
};