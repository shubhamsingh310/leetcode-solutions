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
class Solution {
public:
      void inorderStore(vector<int>&ans,TreeNode* root)
    {
        if(root)
        {
           inorderStore(ans,root->left);
            ans.push_back(root->val);
            inorderStore(ans,root->right); 
        }
    }
  
    TreeNode* constructBSTFromInorder(vector<int>&ans,TreeNode*&root,int l,int h)
    {
        int mid=(l+h)/2;
        if(l>h)
        {
            return root;
        }
        root=new TreeNode(ans[mid]);
        root->left=constructBSTFromInorder(ans,root->left,l,mid-1);
        root->right=constructBSTFromInorder(ans,root->right,mid+1,h);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        
        vector<int>ans;
        inorderStore(ans,root);
       
        TreeNode* root2=NULL;
        constructBSTFromInorder(ans,root2,0,ans.size()-1);
       
        return root2;
    }
};