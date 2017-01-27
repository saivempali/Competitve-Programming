/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if(root != NULL)
        {
            queue<TreeLinkNode*> q;
            q.push(root);
            
            while(!q.empty())
            {
                vector<TreeLinkNode*> arr;
                
                while(!q.empty())
                {
                    arr.push_back(q.front());
                    q.pop();
                }
                
                for(int i=0; i<arr.size()-1; i++)
                {
                    arr[i]->next = arr[i+1];
                    if(arr[i]->left != NULL)
                        q.push(arr[i]->left);
                    if(arr[i]->right != NULL)
                        q.push(arr[i]->right);
                    
                }
                
                if(arr[arr.size()-1]->left != NULL)
                    q.push(arr[arr.size()-1]->left);
                if(arr[arr.size()-1]->right != NULL)
                    q.push(arr[arr.size()-1]->right);
                
                arr[arr.size()-1]->next = NULL;
            }
            
        }
    }
};
