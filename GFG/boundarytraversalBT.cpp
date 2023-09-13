#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};
vector <int> boundary(Node *root);
void bottomview(Node*,vector<int>&);
void leftview(Node*,vector<int>&);
void rightview(Node*,vector<int>&);

int main(){

    Node* root=new Node;
    root->data=4;
    root->left=new Node;
    root->left->data=10;
    // root->right=new Node;
    // root->right->data=3;
    root->left->left=new Node;
    root->left->left->data=5;
    root->left->right=new Node;
    root->left->right->data=5;
    // root->right->left=new Node;
    // root->right->left->data=6;
    // root->right->right=new Node;
    // root->right->right->data=7;
    // root->left->left->left=new Node;
    // root->left->left->left->data=6;
    root->left->left->right=new Node;
    root->left->left->right->data=6;
    root->left->right->left=new Node;
    root->left->right->left->data=7;
    root->left->left->right->left=new Node;
    root->left->left->right->left->data=8;
    root->left->left->right->right=new Node;
    root->left->left->right->right->data=8;
    root->left->left->right->left->left=new Node;
    root->left->left->right->left->left->data=11;
    root->left->left->right->right->left=new Node;
    root->left->left->right->right->left->data=3;
    root->left->left->right->right->right=new Node;
    root->left->left->right->right->right->data=4;
    root->left->left->right->left->left->left=new Node;
    root->left->left->right->left->left->left->data=3;
    root->left->left->right->left->left->left->left=new Node;
    root->left->left->right->left->left->left->left->data=5;
    root->left->left->right->left->left->left->right=new Node;
    root->left->left->right->left->left->left->right->data=8;
    root->left->left->right->right->left->left=new Node;
    root->left->left->right->right->left->left->data=5;
    root->left->left->right->right->left->right=new Node;
    root->left->left->right->right->left->right->data=6;
    root->left->left->right->right->right->left=new Node;
    root->left->left->right->right->right->left->data=11;
    root->left->right->left->right=new Node;
    root->left->right->left->right->data=8;


    vector<int> ans;
    ans=boundary(root);
    return 0;
}
vector <int> boundary(Node *root){
    /*
    idea:
    1. then we insert all nodes visible from left end including root
    2. then we insert all nodes visible from bottom
    3. then we insert nodes visible from right except root and reverse it
    */
    vector<int> ans;
    ans.push_back(root->data);
   //LEFT VIEW OF BT
    leftview(root->left,ans);
    
    //BOTTOM VIEW
    bottomview(root->left,ans);
    bottomview(root->right,ans);

    //RIGHT VIEW OF BT
    vector<int> rightitems;
    rightview(root->right,rightitems);

    //ADD RIGHT ITEMS TO ANS
    for(int i=rightitems.size()-1;i>=0;i--){
        ans.push_back(rightitems[i]);
    }

    for(auto val:ans)
        cout<<val<<",";
    cout<<endl;

    return ans;
}
void bottomview(Node* root,vector<int>& ans){
    if(root==nullptr)
        return;

    if(root->left==nullptr and root->right==nullptr){
        ans.push_back(root->data);
        return;
    }
    
    if(root->left)
        bottomview(root->left,ans);
    
    if(root->right)
        bottomview(root->right,ans);
}
void leftview(Node* root,vector<int>& ans){
    if(root==nullptr)
        return;

    if(root->left==nullptr and root->right==nullptr)
        return;
    
    ans.push_back(root->data);
    if(root->left)
        leftview(root->left,ans);
    else
        leftview(root->right,ans);
}
void rightview(Node* root,vector<int>& ans){
    if(root==nullptr)
        return;

    if(root->left==nullptr and root->right==nullptr)
        return;
    
    ans.push_back(root->data);
    if(root->right)
        rightview(root->right,ans);
    else
        rightview(root->left,ans);
}