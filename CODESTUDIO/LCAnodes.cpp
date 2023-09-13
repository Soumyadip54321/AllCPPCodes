#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class BinaryTreeNode {
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

int lcaOfThreeNodes(BinaryTreeNode* root, int node1, int node2, int node3);
bool lca(BinaryTreeNode*,vector<int>&,int);
void inorder(BinaryTreeNode*);

int main(){
    BinaryTreeNode* root=new BinaryTreeNode(1);
    root->left=new BinaryTreeNode(2);
    root->right=new BinaryTreeNode(3);
    root->left->left=new BinaryTreeNode(4);
    root->left->right=new BinaryTreeNode(5);
    root->right->left=new BinaryTreeNode(6);
    root->right->right=new BinaryTreeNode(7);
    root->left->left->left=new BinaryTreeNode(8);
    root->left->left->right=new BinaryTreeNode(9);
    root->left->left->left->left=new BinaryTreeNode(10);
    root->left->left->right->left=new BinaryTreeNode(11);

    inorder(root);
    cout<<lcaOfThreeNodes(root,8,9,11)<<endl;
    return 0;
}
int lcaOfThreeNodes(BinaryTreeNode* root, int node1, int node2, int node3){
    vector<int> n1,n2,n3;
    int lcaof3nodes=0,start;
    if(lca(root,n1,node1) && lca(root,n2,node2) && lca(root,n3,node3)){
        cout<<endl;
        for(auto val:n1)
            cout<<val<<",";
        cout<<endl;
        
        for(auto val:n2)
            cout<<val<<",";
        cout<<endl;

        for(auto val:n3)
            cout<<val<<",";
        cout<<endl;

        start=min(n1.size(),min(n2.size(),n3.size()));

        for(int i=start-1;i>=0;i--){
            if(n1[i]==n2[i] && n1[i]==n3[i] && n2[i]==n3[i]){
                lcaof3nodes=n1[i];
                break;
            }
        }
    }
    return lcaof3nodes;
}
bool lca(BinaryTreeNode* root,vector<int>& path,int value){
    if(root==nullptr)
        return false;

    path.push_back(root->data);
    if(root->data==value)
        return true;
    
    if(lca(root->left,path,value) || lca(root->right,path,value))
        return true;
    
    path.pop_back();
    return false;
}
void inorder(BinaryTreeNode* root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}