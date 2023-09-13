#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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
 vector<int> findSpiral(Node *root);

int main(){
    vector<int> res;
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(60);
    // root->right->left=new Node(5);
    // root->right->right=new Node(4);

    res=findSpiral(root);
    return 0;
}
 vector<int> findSpiral(Node *root){
    queue<pair<Node*,int>> q;
    stack<int> s;
    vector<int> res;

    q.push({root,0});

    while (not(q.empty()))
    {
        int size=q.size();

        for(int i=0;i<size;i++){
            Node* n=q.front().first;
            int level=q.front().second;
            q.pop();

            if(level%2!=0)
                res.push_back(n->data);
            else
                s.push(n->data);
            
            if(n->left)
                q.push({n->left,level+1});
            if(n->right)
                q.push({n->right,level+1});
        }

        while (not(s.empty()))
        {
            res.push_back(s.top());
            s.pop();
        }
    }

    // for(auto val:res)
    //     cout<<val<<",";
    // cout<<endl;
    return res;
 }