/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
   
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

    vector<int> inorder(TreeNode* root){
        vector<int> in;
        stack<TreeNode*> mystack;
        TreeNode* cur = root;
        bool done = 0;
        while(!done){
            if(cur != NULL){
                mystack.push(cur);
                cur = cur->left;
            }
            
            else{
                if(!mystack.empty()){
                    cur = mystack.top();
                    mystack.pop();
                    in.push_back(cur->val);
                    cur = cur->right;
                }
                
                else
                    done = 1;
            }
            
        }
        return in;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
            
        if(root != NULL && root->left == NULL && root->right == NULL)
            return true;
            
        if(root!= NULL && (root->left == NULL || root->right == NULL))
            return false;
            
        if(root->left->val != root->right->val)
            return false;
            
        vector<int> left = inorder(root->left);
        vector<int> right = inorder(root->right);
        
        if(left.size() == right.size()){
            int last = left.size()-1;
            int i;
            for( i=0; i<left.size(); i++){
                if(left[i] == right[last]){
                    last--;
                    continue;
                }
                else
                    break;
            }
            
            if(i == left.size())
                return true;
            else
                return false;
        }
        
        else 
            return false;
        
    }
}