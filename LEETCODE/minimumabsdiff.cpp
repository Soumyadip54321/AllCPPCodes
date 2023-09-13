#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> nodeval;
vector<int> levelwiseval;
//priority_queue<int,vector<int>,greater<int>> pq;
int mind=INT_MAX;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
int getMinimumDifference(TreeNode* root);
void inorder(TreeNode*);
void computediff(TreeNode*,TreeNode*);
int maxLevelSum(TreeNode* root);

int main(){
    TreeNode* root=new TreeNode(989);
    //root->left=new TreeNode(10250);
    root->right=new TreeNode(10250);
    root->right->left=new TreeNode(98693);
    root->right->right=new TreeNode(-89388);
    root->right->right->right=new TreeNode(-32127);

    //cout<<getMinimumDifference(root)<<endl;
    cout<<maxLevelSum(root)<<endl;
    return 0;
}
int getMinimumDifference(TreeNode* root){
    //naive approach
    /*
    idea:
    1. we consider inorder values in an array
    2. since its a BST difference between first 2 elements will be minimum
    */

   //APPROACH 1
   /*
   1. we pick all elements in an array
   2. we compute absolute difference between the first two and return
   */
    inorder(root);
    int mindiff=INT_MAX;

    for(int i=0;i<nodeval.size()-1;i++)
        mindiff=min(mindiff,nodeval[i+1]-nodeval[i]);
    return mindiff;

    //APPROACH 2
    /*
    idea:
    1. For every node we compute the difference between its value and its right child
    2. we then put the value in a set/min heap
    3. return the first value of set
    */
   computediff(root->right,root);
   computediff(root->left,root);
   return mind;
}
void inorder(TreeNode* root){
    if(root==nullptr)
        return;

    inorder(root->left);
    nodeval.push_back(root->val);
    inorder(root->right);
}
void computediff(TreeNode* root,TreeNode* parent){
    if(root==nullptr)
        return;
    
    mind=min(mind,abs(root->val-parent->val));
    computediff(root->right,root);
    computediff(root->left,root);
}
int maxLevelSum(TreeNode* root){
    /*
    idea:
    1. we apply bfs over here and put values in an array with indices denoting levels
    */
   queue<TreeNode*> q;
   q.push(root);

   while (not(q.empty()))
   {    
        int length=q.size();
        int sum=0;
        for(int i=0;i<length;i++){

            sum+=q.front()->val;
            if(q.front()->left)
            q.push(q.front()->left);

            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        levelwiseval.push_back(sum);
   }
    // for(auto val:levelwiseval)
    //     cout<<val<<",";
    // cout<<endl;

    int maxsum=INT_MIN,level1;

    for(int i=0;i<levelwiseval.size();i++){
        if(levelwiseval[i]>maxsum){
            maxsum=levelwiseval[i];
            level1=i+1;
        }
    }
    return level1;
}