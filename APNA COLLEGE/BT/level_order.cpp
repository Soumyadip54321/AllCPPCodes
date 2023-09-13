#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node (int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void printlevelorder(Node*);
int sumatk(Node*,int);
int countnodes(Node*);
int sumallnodes(Node*);
int computeheight(Node*);
int caldiameter(Node*);

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //lvel order
    //printlevelorder(root);
    //cout<<sumatk(root,2)<<endl;
    //cout<<countnodes(root)<<endl;
    //cout<<sumallnodes(root)<<endl;
    //cout<<computeheight(root)<<endl;
    cout<<caldiameter(root)<<endl;
    return 0;
}
void printlevelorder(Node* root){
    if(root==nullptr)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (not(q.empty()))
    {
        Node* node=q.front();
        q.pop();
        if(node!=nullptr){
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())
            q.push(nullptr);
    }
}
int sumatk(Node* root,int K){
    if(root==nullptr)
        return -1;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    int level=0;
    int sum=0;

    while (not(q.empty()))
    {
        Node* node=q.front();
        q.pop();

        if(node!=nullptr){
            if(level==K)
                sum+=node->data;

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){
            level++;
            q.push(nullptr);
        }
    }
    return sum;
}

/*here we count number of nodes present in the tree*/
int countnodes(Node* root){
    if(root==nullptr)
        return 0;
    return countnodes(root->left)+countnodes(root->right)+1;
}
int sumallnodes(Node* root){
    if(root==nullptr)
        return 0;
    return root->data+sumallnodes(root->left)+sumallnodes(root->right);
}
int computeheight(Node* root){
    if(root==nullptr)
        return 0;
    return 1+max(computeheight(root->left),computeheight(root->right));
}
/*Takes T(n)=O(n) for every node it computes the height at that*/
int caldiameter(Node* root){
    if(root==nullptr)
        return 0;
    
    /*case when diameter goes through tree root*/
    int caldiathruroot=computeheight(root->left)+computeheight(root->right)+1;

    /*case when diameter doesn't go through root*/
    return max(caldiathruroot,max(caldiameter(root->left),caldiameter(root->right)));
}