#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};
vector<int> zigzagTreeTraversal(TreeNode *root);

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    //root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(6);
    //root->right->right->left=new TreeNode(4);
    root->left->left->right=new TreeNode(7);
    //root->left->right->right=new TreeNode(11);

    vector<int> zigzagitems;
    zigzagitems=zigzagTreeTraversal(root);
    return 0;
}
vector<int> zigzagTreeTraversal(TreeNode *root){
    /*
    idea:
    1. we maintain a stack of node value and a queue of nodes
    2. when at odd level nodes we insert them in the stack from left to right as we'd in a BFS traversal
    3. when at even level nodes we simply put them in queue
    */

    stack<int> s;
    queue<TreeNode*> q;
    vector<int> zigzagitems;

    q.push(root);
    int level=0;
    

    while (not(q.empty()))
    {
        int size=q.size();

        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();

            if(level%2==0){
                zigzagitems.push_back(node->data);  //at even level we insert them directly into vector
            }
            else{
                s.push(node->data);             //at odd levels we only insert items from left->right into a stack
            }

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        while (not(s.empty()))
        {
            zigzagitems.push_back(s.top());
            s.pop();
        }
        level++;
    }

    // for(auto val:zigzagitems)
    //     cout<<val<<",";
    // cout<<endl;
    return zigzagitems;
}