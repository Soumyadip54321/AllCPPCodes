#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class TreeNode {
public :
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode() {
        if (left){
        delete left;
        }
        if (right){
        delete right;
        }
    }
};
vector<vector<int>> diagonal(TreeNode* root);

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    // root->left->right=new TreeNode(6);
    // root->left->right->right=new TreeNode(7);
    root->right->left=new TreeNode(5);
    root->right->left->right=new TreeNode(6);

    vector<vector<int>> dia;
    dia=diagonal(root);
    return 0;
}
vector<vector<int>> diagonal(TreeNode* root){
    /*
    idea:
    1. we use a queue here and put the root in first followed by NULL that acts as a delimiter to indicate start of a new diagonal
    2. we put all left child of current node into queue that begins the next diagonal if present
    3. we put the value at current node in vector and if present move to its right child repeating the above process
    */
    queue<TreeNode*> q;
    vector<vector<int>> diaitems;

    if(root==nullptr)
        return diaitems;

    q.push(root);
    q.push(NULL);               /*serves as a delimiter for next set of diagonal*/

    while (true)
    {
        vector<int> d;
        TreeNode* temp=q.front();
        q.pop();

        while (temp!=NULL)
        {
            d.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            temp=temp->right;

            if(temp==NULL){
                temp=q.front();
                q.pop();
            }
        }
        diaitems.push_back(d);

        if(q.empty())
            break;

        q.push(temp);
    }
    // for(int i=0;i<diaitems.size();i++){
    //     cout<<"{";
    //     for(auto val:diaitems[i])
    //         cout<<val<<",";
    //     cout<<"}"<<endl;
    // }
    return diaitems;
}   