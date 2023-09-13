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
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
vector<int> rightView(Node *root);

int main(){
    vector<int> res;
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->left=new Node(8);
    root->left->left->right=new Node(13);

    res=rightView(root);
    return 0;
}
vector<int> rightView(Node *root){
    vector<int> res;
    queue<Node*> q;
    q.push(root);

    while (not(q.empty()))
    {
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* node=q.front();
            q.pop();

            if(i==n-1)
                res.push_back(node->data);

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }

    return res;
}