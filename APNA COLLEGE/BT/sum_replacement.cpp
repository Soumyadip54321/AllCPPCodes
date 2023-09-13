#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
int sumreplacement(Node*);
void inorder(Node*);
bool isBalanced(Node*);
int height(Node*);
int LCA(Node*,int,int);
bool findpath(Node*,int,vector<int>&);

int main(){
    Node* node=new Node(1);
    node->left=new Node(2);
    node->right=new Node(3);
    node->left->left=new Node(4);
    node->right->left=new Node(5);
    node->right->right=new Node(6);
    node->right->left->left=new Node(7);

    //node->data=sumreplacement(node);
    inorder(node);
    cout<<endl;
    cout<<isBalanced(node)<<endl;
    int pc=LCA(node,6,7);

    cout<<"LCA is: "<<pc<<endl;
    return 0;
}
int sumreplacement(Node* root){
    if(root==nullptr)
        return 0;
    return root->data+=sumreplacement(root->left)+sumreplacement(root->right);
}

/*T(n)=O(n) This is the time complexity of sum replacement*/
void inorder(Node* root){
    if(root==nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int height(Node* root){
    if(root==nullptr)
        return 0;

    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(Node* root){
    if(root==nullptr)
        return true;

    if(isBalanced(root->left)==false)
        return false;
    if(isBalanced(root->right)==false)
        return false;
    
    if(abs(height(root->left)-height(root->right))<=1)
        return true;
    return false;
}
/*This function takes T(n)=O(n^2) time since for each node the height function called is executed at most O(n) times
and there exists n such vertices*/
int LCA(Node* root,int d1,int d2){
    vector<int> p1,p2;

    if(findpath(root,d1,p1)==false || findpath(root,d2,p2)==false)
        return -1;
    
    for(auto item:p1)
        cout<<item<<" ";

    cout<<endl;

    for(auto item:p2)
        cout<<item<<" ";
    
    int pc;
    for(pc=0;pc<p1.size() && p2.size();pc++){
        if(p1[pc]!=p2[pc])
            break;
    }
    return p1[pc-1];
}
bool findpath(Node* root,int nodeval,vector<int>& path){
    if(root==nullptr)
        return false;

    path.push_back(root->data);
    if(root->data==nodeval){
        return true;
    }

    if(findpath(root->left,nodeval,path) || findpath(root->right,nodeval,path))
        return true;

    path.pop_back();
    return false;
}
