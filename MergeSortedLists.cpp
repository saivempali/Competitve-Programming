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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL || l2 == NULL)
        {
            if(l1 == NULL && l2!=NULL)
                return l2;
                
            if(l2 == NULL && l1!=NULL)
                return l1;
            
            return l1;
        }
            
        
            
        if(l1->next == NULL && l2->next == NULL)
        {
            if(l1->val >= l2->val)
            {
                l2->next = l1;
                return l2;
            }
            else
            {
                l1->next = l2;
                return l1;
            }
        }
        
        ListNode* head,*res = NULL;
        while(l1 != NULL && l2!= NULL)
        {
            if(l1->val <= l2->val)
            {
                if(res == NULL)
                {
                    res = new ListNode(l1->val);
                    head = res;
                    res->val = l1->val;
                    res->next = NULL;
                    l1 = l1->next;
                }
                else
                {
                    res->next = new ListNode(l1->val);
                    res = res->next;
                    res->val = l1->val;
                    res->next = NULL;
                    l1 = l1->next;
                }
            }
            
            else if(l1->val > l2->val)
            {
                if(res == NULL)
                {
                    res = new ListNode(l2->val);
                    head = res;
                    res->val = l2->val;
                    res->next = NULL;
                    l2 = l2->next;
                }
                else
                {
                    res->next = new ListNode(l2->val);
                    res = res->next;
                    res->val = l2->val;
                    res->next = NULL;
                    l2 = l2->next;
                }
            }
            
          
        }
        
        while(l1 != NULL)
        {
            res->next = new ListNode(l1->val);
            res = res->next;
            res->val = l1->val;
            res->next = NULL;
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            res->next = new ListNode(l2->val);
            res = res->next;
            res->val = l2->val;
            res->next = NULL;
            l2 = l2->next;
        }
    
        return head;    
    }
};