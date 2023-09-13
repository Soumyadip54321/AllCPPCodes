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
Node * inOrderSuccessor(Node *root, Node *x);
void inorder(Node*,vector<Node*>&);

int main(){
    Node* insucc;
    Node* root=new Node(20);
    root->left=new Node(18);
    root->right=new Node(22);
    root->left->left=new Node(4);
    root->left->right=new Node(12);
    root->left->right->left=new Node(10);
    root->left->right->right=new Node(14);

    insucc=inOrderSuccessor(root,root->right);
    if(not(insucc))
        cout<<0<<endl;
    else
        cout<<insucc->data<<endl;

    return 0;
}
Node* inOrderSuccessor(Node *root, Node *x){
    vector<Node*> nodesinordered;
    inorder(root,nodesinordered);

    for (int i = 0; i < nodesinordered.size(); i++)
    {
        if(nodesinordered[i]==x and i!=nodesinordered.size()-1)
            return nodesinordered[i+1];
    }
    return nullptr;
}
void inorder(Node* root,vector<Node*>& v){
    if(root==nullptr)
        return;
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}