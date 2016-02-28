/*
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ptr = l1;
        ListNode* prev = l1;
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL && l2!=NULL)
            return l2;
        else if(l1 != NULL && l2==NULL)
            return l1;
        else
        {
            while(l1!=NULL && l2!=NULL)
            { 
                
                if((l1->val+l2->val+carry) > 9 )
                {
                    l1->val = (l1->val+l2->val+carry) % 10;
                    prev = l1;
                    l1=l1->next;
                    l2=l2->next;
                    carry = 1;
                }
                else
                {
                    
                    l1->val = (l1->val+l2->val+carry);
                    prev = l1;
                    l1=l1->next;
                    l2=l2->next;
                    carry = 0;
                }
            }
            if(l2!=NULL)
            {
                while(l2!=NULL)
                {
                   
                    if((l2->val + carry) > 9)
                    {
                        l1 = new ListNode((l2->val+carry)%10);
                        carry = 1;
                    }
                    else
                    {
                        l1 = new ListNode((l2->val+carry));
                        carry = 0;
                    }                    
                    prev->next = l1;
                    prev = l1;
                    l1 = l1->next;
                    l2 = l2->next;
                }
            }
            if(l1!=NULL)
            {
                while(l1!=NULL)
                {
                    if((l1->val + carry) > 9)
                    {
                        l1->val = (l1->val+carry) % 10;
                        carry = 1;
                    }
                    else
                    {
                        l1->val = (l1->val+carry);
                        carry = 0;
                    }
                    prev->next = l1;
                    prev = l1;
                    l1 = l1->next;
               }
            }
            if(carry == 1 && l1 == NULL && l2 == NULL)
            {
                ListNode* n = new ListNode(1);
                prev->next = n;
            }
    
        }
        return ptr;
    }
};