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
        left=right=nullptr;
    }
};

node* buildBST(int*,int);
node* formtree(node*,int);
bool searchnode(node*,int);
void inorder(node*);
node* deletefromBST(node*,int);
node* inorderpred(node*);

int main(){
    int arr[]={4,2,5,1,3,6};
    node* root;
    root=buildBST(arr,6);

    // inorder(root);
    //cout<<"\n"<<searchnode(root,23)<<endl;
    deletefromBST(root,4);
    inorder(root);
    return 0;
}
node* buildBST(int* arr,int n){
    node* root=nullptr;

    for(int i=0;i<n;i++)
        root=formtree(root,arr[i]);
    return root;
}
node* formtree(node* root,int val){
    if(root==nullptr){
        node* root=new node(val);
        return root;
    }
    if(val<root->data)
        root->left=formtree(root->left,val);
    else
        root->right=formtree(root->right,val);
    return root;
}
void inorder(node* root){
    if(root==nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool searchnode(node* root,int val){
    if(root==nullptr)
        return false;
    
    if(root->data==val)
        return true;
    
    if(searchnode(root->left,val) || searchnode(root->right,val))
        return true;
    return false;
}
node* deletefromBST(node* root,int val){                /* to search,delete and return the root ptr */
    if(val<root->data){
        root->left=deletefromBST(root->left,val);
    }
    else if(val>root->data)
        root->right=deletefromBST(root->right,val);
    else{
        if(root->left==nullptr){
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==nullptr){
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* temp=inorderpred(root->left);
        root->data=temp->data;
        root->left=deletefromBST(root->left,temp->data);
    }
    return root;
}

node* inorderpred(node* root){
    if(root->right==nullptr)
        return root;
    
    return inorderpred(root->right);
}