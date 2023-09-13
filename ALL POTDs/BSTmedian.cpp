#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
float findMedian(struct Node *root);
void inorder(Node*,vector<int>&);

int main(){
    Node* root=new Node(6);
    root->left=new Node(3);
    root->right=new Node(8);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->left=new Node(7);
    root->right->right=new Node(9);

    cout<<findMedian(root);
    return 0;
}
float findMedian(struct Node *root){
    /*
    idea:   
    1. flatten out values in inorder
    2. find the median 
    */
   vector<int> nodesininorder;
   inorder(root,nodesininorder);

   int len=nodesininorder.size();

   if(len%2!=0){
        return nodesininorder[(len-1)/2];
   }
    float ans;
    ans=(nodesininorder[len/2]*1.0+nodesininorder[(len/2)-1]*1.0)/2.0;
    return ans;
}
void inorder(Node* root,vector<int>& v){
    if(root==nullptr)
        return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}