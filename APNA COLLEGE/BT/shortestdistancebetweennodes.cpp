#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
int distance(node*,int,int);
bool LCA(node*,int,vector<int>&);
void inorder(node*);

int main(){
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6);

    //inorder(root);
    cout<<"shortest distance between nodes: "<<distance(root,2,6)<<endl;
    return 0;
}
int distance(node* root,int n1,int n2){
    int count=0,lca;
    vector<int> p1;
    vector<int> p2;

    if(LCA(root,n1,p1)==false || LCA(root,n2,p2)==false)          //indicates one or more nodes doesn't exist in tree
        return -1;
    
    // cout<<endl;
    // for(auto val:p1)
    //     cout<<val<<" ";
    // cout<<endl;

    // for(auto val:p2)
    //     cout<<val<<" ";
    // cout<<endl;


    /*if obtained we search in p1 and p2 distance to LCA for both n1,n2*/
    for(int i=0;i<p1.size() && p2.size();i++){
        if(p1[i]!=p2[i]){
            break;
        }
        lca=p1[i];
    }
    //cout<<"LCA: "<<lca<<endl;

    for(int i=p1.size()-1;i>=0;i--){
        if(p1[i]==lca)
            break;
        count++;
    }
    for(int i=p2.size()-1;i>=0;i--){
        if(p2[i]==lca)
            break;
        count++;
    }
    return count;
}

bool LCA(node* root,int nodeval,vector<int>& path){
    /*idea: 
    1.  we try and compute the LCA of two given nodes in BT
    2.  Then we traverse from the node to the LCA in both
    3.  we sum the number of edges found*/

    if(root==nullptr)           //base condition
        return false;

    path.push_back(root->data);

    if(root->data==nodeval){
        return true;
    }

    if(LCA(root->left,nodeval,path) || LCA(root->right,nodeval,path))
        return true;
    
    path.pop_back();
    return false;
}
void inorder(node* root){
    if(root==nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
