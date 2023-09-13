#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
Node* buildtree(int*,int*,int,int);
int look(int*,int,int,int);
void inorderdisplay(Node*);

int main(){
    int postorder[]={4,2,5,3,1},inorder[]={4,2,1,5,3};

    //build tree
    Node* node=buildtree(postorder,inorder,0,4);
    inorderdisplay(node);
    return 0;
}
Node* buildtree(int* postorder,int* inorder,int start,int end){
    if(start>end)
        return nullptr;

    static int idx=end;
        
    int curr=postorder[idx];
    Node* node=new Node(curr);
    idx--;

    if(start==end)
        return node;

    int pos = look(inorder,start,end,curr);
    node->right=buildtree(postorder,inorder,pos+1,end);
    node->left=buildtree(postorder,inorder,start,pos-1);

    return node;
}
int look(int* inorder,int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr)
            return i;
    }
    return -1;
}
void inorderdisplay(Node* root){
    if(root==nullptr)
        return;

    inorderdisplay(root->left);
    cout<<root->data;
    inorderdisplay(root->right);
}