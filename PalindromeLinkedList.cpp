/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 #include<stack>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
            
        if(head->next->next == NULL)
        {
            if(head->val == head->next->val)
                return true;
                
            else
                return false;
        }
        
        ListNode *r1 = head;
        ListNode *r2 = head;
        
        stack<int> mystack;
        
        while(r2->next != NULL && r2->next->next != NULL)
        {
            mystack.push(r1->val);
            r1 = r1->next;
            r2 = r2->next->next;
        }
        
        if(r2->next == NULL)
        {
            r1 = r1->next;
        }
        
        else
        {
            mystack.push(r1->val);
            r1 = r1->next;
            
        }
        
        
        
        while(r1 != NULL)
        {
            int top = mystack.top();
            mystack.pop();
            if(top != r1->val)
            {
                return false;
            }
        
            r1 = r1->next;
        }
        
        return true;      
    }
};