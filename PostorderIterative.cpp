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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> result;
        if(root == NULL)
            return result;
            
        int done = 0;
        TreeNode* cur = root;
        stack<TreeNode*> mystack;
        
        do
        {
            while(cur != NULL)
            {
                if(cur->right != NULL)
                    mystack.push(cur->right);
                mystack.push(cur);
                cur = cur->left;
            }
            
            cur = mystack.top();
            mystack.pop();
            
            if(mystack.empty())
            {
                result.push_back(cur->val);
                break;
            }
            if(cur->right != NULL && mystack.top() == cur->right)
            {
                mystack.pop();
                mystack.push(cur);
                cur = cur->right;
            }
            else
            {
                result.push_back(cur->val);
                for(int i=0; i<result.size(); i++)
                    cout<<result[i]<<" ";
                cout<<endl;
                cur = NULL;
            }
            
            if(!mystack.empty())
                cout<<"stack is not empty\n"<<mystack.top()->val<<endl;
        }while(!mystack.empty());
        return result;
    }
};