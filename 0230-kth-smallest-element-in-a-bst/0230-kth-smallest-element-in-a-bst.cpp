/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
public:
int solve(TreeNode*root,int& k){
        
		//base case
        if(root==NULL){
            return -1;
        }
        //LNR inorder 
        //left side
        int left=solve(root->left,k);
        if(left!=-1){
            return left;
        }
        
        //Node 
        k--;           
        if(k==0)
            return root->val;
        
        //right side
        return solve(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans=solve(root,k);
        return ans;
        
    }
};