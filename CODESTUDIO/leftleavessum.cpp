#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class TreeNode {
    public:
     int val;
     TreeNode *left;
     TreeNode *right;

     TreeNode(int val) {
         this->val = val;
         left = NULL;
         right = NULL;
     }
};
int sumOfLeftLeaves(TreeNode *root);
int computesum(TreeNode*,TreeNode*);

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->left->left->left=new TreeNode(8);
    // root->left->left->left->left=new TreeNode(11);
    // root->left->left->left->left->right=new TreeNode(12);
    // root->left->left->left->right=new TreeNode(10);
    // root->left->left->left->right->left=new TreeNode(13);
    // root->left->left->left->right->left->left=new TreeNode(14);

    root->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    // root->right->left->right=new TreeNode(5);
    // root->right->left->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);


    cout<<sumOfLeftLeaves(root);
    return 0;
}
int sumOfLeftLeaves(TreeNode *root){
    if(root==nullptr)
        return 0;
    return computesum(root->left,root)+computesum(root->right,root);
}
int computesum(TreeNode* root,TreeNode* parent){
    if(root->left==nullptr && root->right==nullptr && parent->left==root)
        return root->val;
    
    if(root->left && root->right)
        return computesum(root->left,root)+computesum(root->right,root);
    
    if(root->left)
        return computesum(root->left,root);
    
    if(root->right)
        return computesum(root->right,root);
    return 0;
}