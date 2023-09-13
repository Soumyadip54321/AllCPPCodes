#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class BinaryTreeNode{
public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
unordered_map<BinaryTreeNode*,bool> visited;
vector<BinaryTreeNode*> printNodesAtDistanceK(BinaryTreeNode* root, BinaryTreeNode* target, int K);
void getparents(BinaryTreeNode*,unordered_map<BinaryTreeNode*,BinaryTreeNode*>&);

int main(){
    BinaryTreeNode* root=new BinaryTreeNode(1);
    root->left=new BinaryTreeNode(2);
    root->right=new BinaryTreeNode(3);
    root->left->left=new BinaryTreeNode(4);
    root->left->right=new BinaryTreeNode(5);
    // root->right->left=new BinaryTreeNode(0);
    // root->right->right=new BinaryTreeNode(8);
    // root->left->right->left=new BinaryTreeNode(7);
    // root->left->right->right=new BinaryTreeNode(4);
    root->left->left->left=new BinaryTreeNode(6);

    vector<BinaryTreeNode*> t;
    t=printNodesAtDistanceK(root,root->left->right,3);
    return 0;
}
vector<BinaryTreeNode*> printNodesAtDistanceK(BinaryTreeNode* root, BinaryTreeNode* target, int K){
    /*
    idea:
    1. we run a BFS at first to find parents of all nodes to help us traverse up form the target node as well
    2. we then run BFS from our target node towards left,right and up and maintain a visited array so that once we've visited a node we do not again visit it at the same time we reduce our distance count by 1
    3. when k==0 we include all nodes into the vector and return
    */
    vector<BinaryTreeNode*> res;
    unordered_map<BinaryTreeNode*,BinaryTreeNode*> parent;
    queue<pair<BinaryTreeNode*,int>> q;
    q.push({target,K});

    getparents(root,parent);
    //we start at the targetnode and run bfs
    visited[target]=true;

    while (not(q.empty()))
    {
        int qs=q.size();
        int d=q.front().second;

        if(d==0)
            break;

        for(int i=0;i<qs;i++){
            BinaryTreeNode* node=q.front().first;
            q.pop();

            if(node->left && not(visited[node->left])){
                q.push({node->left,d-1});
                visited[node->left]=true;
            }
            if(node->right && not(visited[node->right])){
                q.push({node->right,d-1});
                visited[node->right]=true;
            }
            if(parent[node] && not(visited[parent[node]])){
                q.push({parent[node],d-1});
                visited[parent[node]]=true;
            }
        }
    }
    //queue now contains only those elements which are at a distance K from targetnode
    while (not(q.empty()))
    {
        res.push_back(q.front().first);
        q.pop();
    }
    // for(auto node:res)
    //     cout<<node->data<<",";
    // cout<<endl;
    return res;
}
void getparents(BinaryTreeNode* root,unordered_map<BinaryTreeNode*,BinaryTreeNode*>& m){
    queue<BinaryTreeNode*> q;
    q.push(root);

    while (not(q.empty()))
    {
        BinaryTreeNode* node=q.front();
        q.pop();

        if(node->left){
            q.push(node->left);
            m[node->left]=node;
        }
        if(node->right){
            q.push(node->right);
            m[node->right]=node;
        }
    }
}