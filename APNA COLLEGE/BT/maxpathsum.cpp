#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <limits.h>
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

int maxpathsum(node*);
void inorder(node*);
int result=INT_MIN;


int main(){
    node *root=new node(1);
    root->left=new node(-12);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(-6);

    inorder(root);
    cout<<endl;
    cout<<"maximum path sum is: "<<maxpathsum(root)<<endl;
    return 0;
}
void inorder(node* root){
    if(root==nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int maxpathsum(node* root){
    if(root==nullptr)
        return 0;
    
    int left=maxpathsum(root->left);
    int right=maxpathsum(root->right);

    int nodemax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    result=max(result,nodemax);

    int singlepathsum=max(root->data,max(root->data+left,root->data+right));
    return singlepathsum;
    
    
}

