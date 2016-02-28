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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL)
            return result;
            
        queue<TreeNode*> q;
        
        TreeNode* temp = root;
        
        q.push(temp);
        
        int zigzag = 0;
        
        while(!q.empty())
        {
            vector<int> v;
            vector<TreeNode*> arr;
            while(!q.empty())
            {
                arr.push_back(q.front());
                q.pop();
            }
            
            if(zigzag == 0)
            {
                for(int i=0; i<arr.size();i++)
                {
                    v.push_back(arr[i]->val);
                    if(arr[i]->left != NULL){
                        q.push(arr[i]->left);
                    }
                    if(arr[i]->right != NULL){
                        q.push(arr[i]->right);
                    }
                }
                result.push_back(v);
                zigzag = 1;
            }
            else
            {
                for(int i=0; i<arr.size();i++)
                {
                    if(arr[i]->left != NULL){
                        q.push(arr[i]->left);
                    }
                    if(arr[i]->right != NULL){
                        q.push(arr[i]->right);
                    }
                }
                
                for(int i=arr.size()-1; i>=0;i--)
                {
                    v.push_back(arr[i]->val);
                }
                
                result.push_back(v);
                zigzag = 0;
            }
            
        }
        
        return result;
    }
};