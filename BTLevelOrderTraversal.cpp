/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL){
            cout<<"entered if";
            return result;
        }
        
      
        queue<TreeNode*> nodeQ;
        
        TreeNode* temp = root;
        
        nodeQ.push(temp);
        
        if(nodeQ.empty())
            cout<<"q is empty";
            
        int ptr=0;
        while(!nodeQ.empty()){
            vector<TreeNode*> arr;
            vector<int> v;
            while(!nodeQ.empty()){
                arr.push_back(nodeQ.front());
                nodeQ.pop();
            }
            
      
            for(int i=0; i<arr.size(); i++){
                v.push_back(arr[i]->val);
                if(arr[i]->left != NULL){
                    nodeQ.push(arr[i]->left);
                }
                if(arr[i]->right != NULL){
                    nodeQ.push(arr[i]->right);
                }
            }
            result.push_back(v);
       
       }
        
        return result;
    }
};