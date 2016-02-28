/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

*/

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
    vector<int> rightSideView(TreeNode* root) {
        
        /*vector<int>result;
        if(root == NULL)
            return result;
        TreeNode* cur = root;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<TreeNode*> arr;
            while(!q.empty())
            {
                arr.push_back(q.front());
                q.pop();
            }
            
            for(int i=0; i<arr.size();i++)
            {
                if(i == arr.size()-1)
                {
                    result.push_back(arr[i]->val);
                }
                
                if(arr[i]->left != NULL)
                    q.push(arr[i]->left);
                
                if(arr[i]->right != NULL)
                    q.push(arr[i]->right);
            }
        }
        return result;*/
        
        vector<vector<int>> result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<TreeNode*> arr;
            while(!q.empty())
            {
                arr.push_back(q.front());
                q.pop();
            }
            
            vector<int> v;
            for(int i=0; i<arr.size();i++)
            {
                v.push_back(arr[i]->val);
                if(arr[i]->left != NULL)
                    q.push(arr[i]->left);
                    
                if(arr[i]->right != NULL)   
                    q.push(arr[i]->right);
                    
            }
            
            result.push_back(v);
        }
        
        cout<<"hi\n";
        for(int i=0; i<result.size();i++)
        {
            cout<<result[i][result[i].size()-1]<<" ";
        }
        
        int leafstart = result[result.size()-1].size()-2;
        for(int i=leafstart; i>=1; i--)
            cout<<result[result.size()-1][i]<<" ";
            
        for(int i=result.size()-1; i>=1; i--)
        {
            cout<<result[i][0]<<" ";
        }
    }
};