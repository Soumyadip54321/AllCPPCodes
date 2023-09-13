#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};
int kthAncestor(Node *root, int k, int node);
bool LCA(Node*,vector<Node*>&,int);
// void inorder(Node*);

int main(){
    Node* root=new Node();
    root->data=1;
    root->left=new Node();
    root->left->data=2;
    root->right=new Node();
    root->right->data=3;
    // root->left->left=new Node();
    // root->left->left->data=4;
    // root->left->right=new Node();
    // root->left->right->data=5;

    cout<<kthAncestor(root,1,3);
    //inorder(root);
    return 0;
}
void inorder(Node* root){
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}
int kthAncestor(Node *root, int k, int node){
    vector<Node*> targetlca;

    if(not(LCA(root,targetlca,node)))
        return -1;
    
    for(int i=targetlca.size()-1;i>=0;i--){
        if(k==0)
            return targetlca[i]->data;
        k--;
    }
    return -1;
}
bool LCA(Node* root,vector<Node*>& targetlca,int target){
    if(root==nullptr)
        return false;
    
    targetlca.push_back(root);
    if(root->data==target)
        return true;
    
    if(LCA(root->left,targetlca,target) || LCA(root->right,targetlca,target))
        return true;

    targetlca.pop_back();
    return false;
}