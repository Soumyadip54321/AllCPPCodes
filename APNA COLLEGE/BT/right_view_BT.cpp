#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
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

void rightview(Node*);


int main(){
    Node* node=new Node(1);
    node->left=new Node(2);
    node->left->left=new Node(3);
    node->left->right=new Node(4);
    node->left->right->left=new Node(5);
    node->left->right->right=new Node(6);
    node->left->right->right->left=new Node(7);
    node->left->right->right->right=new Node(8);


    rightview(node);
    return 0;
}
void rightview(Node* root){
    /*we perform bfs on tree and display only nodes that immediately succedes NULL node entered in queue*/
    queue<Node*> q;
    q.push(root);

    while (not(q.empty()))
    {
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();

            if(i==n-1)
                cout<<curr->data<<" ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
}