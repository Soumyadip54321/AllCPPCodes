#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
bool checkBSTs(TreeNode *root1, TreeNode *root2);
void inorder(TreeNode*,vector<int>&);

int main(){
    TreeNode* root=new TreeNode(8);
    root->left=new TreeNode(5);
    root->right=new TreeNode(10);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(6);
    root->right->right=new TreeNode(7);

    TreeNode* root1=new TreeNode(10);
    root1->left=new TreeNode(5);
    //root1->right=new TreeNode(20);
    root1->left->right=new TreeNode(2);
    root1->left->right->left=new TreeNode(8);
    root1->left->right->left->right=new TreeNode(6);

    cout<<checkBSTs(root,root1);
    return 0;
}
bool checkBSTs(TreeNode *root1, TreeNode *root2){
    vector<int> tree1items,tree2items;
    set<int> s1,s2;
    
    inorder(root1,tree1items);
    inorder(root2,tree2items);

    for(auto item:tree1items)
        s1.insert(item);
    
    for(auto item:tree2items){
        s2.insert(item);
    }
    if(s1==s2)
        return true;
    return false;
}
void inorder(TreeNode* root,vector<int>& items){
    if(root==nullptr)
        return;
    inorder(root->left,items);
    items.push_back(root->data);
    inorder(root->right,items);
}