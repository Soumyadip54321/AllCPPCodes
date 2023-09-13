#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class BinaryTreeNode
    {
public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
int findKthAncestor(BinaryTreeNode *root, int targetNodeVal, int k);
bool LCA(BinaryTreeNode*,int,vector<int>&);

int main(){
    BinaryTreeNode* root=new BinaryTreeNode(1);
    root->left=new BinaryTreeNode(2);
    root->right=new BinaryTreeNode(3);
    root->left->left=new BinaryTreeNode(4);
    root->left->right=new BinaryTreeNode(5);

    cout<<findKthAncestor(root,4,1);
    return 0;
}
int findKthAncestor(BinaryTreeNode *root, int targetNodeVal, int k){
    /*
    idea:
    1. we fin the lca of the target node
    2. Then we traverse all the ancestors from bottom up to find the kth
    */
    vector<int> ancestors;
    if(not(LCA(root,targetNodeVal,ancestors)))
        return -1;
    
    int n=ancestors.size();
    k--;
    for(int i=n-2;i>=0;i--){
        if(k==0)
            return ancestors[i];
        k--;
    }
    return -1;
}
bool LCA(BinaryTreeNode* root,int target,vector<int>& v){
    if(root==nullptr)
        return false;
    
    v.push_back(root->data);
    if(root->data==target)
        return true;
    
    if(LCA(root->left,target,v) || LCA(root->right,target,v))
        return true;

    v.pop_back();
    return false;
}
