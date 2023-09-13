#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
const int M=1e9+7;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool oneSegment(string str);
vector<int> distanceK(TreeNode* root, TreeNode* target, int k);
int countRectangles(int n);
int factorials(int);
// void findnodesatk(TreeNode*,vector<int>&,int);
// bool LCA(TreeNode*,TreeNode*,vector<TreeNode*>&);
// bool finddistnodes(TreeNode*,TreeNode*,int,int&);
void markparents(TreeNode*,unordered_map<TreeNode*,TreeNode*>&,TreeNode*);

TreeNode* targetloc=nullptr;

int main(){
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(6);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(9);
    root->right->right=new TreeNode(4);
    root->left->right->left=new TreeNode(2);
    root->left->right->right=new TreeNode(0);

    string str="00110";

    vector<int> nodesatk;
    //nodesatk=distanceK(root,root->left->right->left,4);
    //cout<<oneSegment(str)<<endl;
    cout<<countRectangles(6261)<<endl;

    return 0;
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    /*
    1. from target we recurse to find node at k distance
    2. we find LCA of target. we then move to all nodes at distance <=k from target.
    3. next we find any node with value k-distance of root.
    */
    // vector<int> allnodesatk;
    // vector<TreeNode*> lca;
    // findnodesatk(target,allnodesatk,k);
    // LCA(root,target,lca);

    // for(int i=0;i<lca.size();i++){
    //     cout<<lca[i]->val<<",";
    // }
    // cout<<endl;

    // //we next find node at distance k in lca and include it in allnodesatk if it exits
    // int start=lca.size()-2,d=k-1;

    // while (d && start>=0)
    // {
    //     int nodeval=0;
    //     if(finddistnodes(lca[start],target,d,nodeval))
    //         allnodesatk.push_back(nodeval);
    //     d--;
    //     start--;
    // }
    // if(d==0 && start>=0){
    //     allnodesatk.push_back(lca[start]->val);
    // }
    // for(auto val:allnodesatk)
    //     cout<<val<<",";
    // cout<<endl;

    //METHOD-II
    unordered_map<TreeNode*,TreeNode*> parent_track; //node->parent
    markparents(root,parent_track,target);

    unordered_map<TreeNode*,bool> visited;
    queue<TreeNode*> q;
    vector<int> result;
    int dis=0;

    q.push(target);         //form: (node,distancefromtarget)
    visited[target]=true;

    while (not(q.empty()))
    {
        int size=q.size();
        if(dis==k)
            break;
        //cout<<dis<<endl;
        dis++;                      //indicates nodes at distance=dis to be inserted

        for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();

            //rightchild insert
            if(not(visited[curr->right]) && curr->right){
                q.push(curr->right);
                visited[curr->right]=true;
            }
            //left child insert
            if(not(visited[curr->left]) && curr->left){
                q.push(curr->left);
                visited[curr->left]=true;
            }
            //parent insert
            if(not(visited[parent_track[curr]]) && parent_track[curr]){
                q.push(parent_track[curr]);
                visited[parent_track[curr]]=true;
            }
        }
        
    }
    //cout<<"i am here"<<endl;
    while (not(q.empty()))
    {
        result.push_back(q.front()->val);
        q.pop();
    }
    
    // for(auto val:result)
    //     cout<<val<<",";
    // cout<<endl;

    return result;
}
//  void findnodesatk(TreeNode* root,vector<int>& v,int k){
//     if(root==nullptr)
//         return;

//     if(k==0 && root){
//         v.push_back(root->val);
//         return;
//     }
//     findnodesatk(root->left,v,k-1);
//     findnodesatk(root->right,v,k-1);
//  }
//  bool LCA(TreeNode* root,TreeNode* target,vector<TreeNode*>& lcaofnode){
//     if(root==nullptr)
//         return false;
    
//     lcaofnode.push_back(root);
//     if(root->val==target->val)
//         return true;
    
//     if(LCA(root->left,target,lcaofnode) || LCA(root->right,target,lcaofnode))
//         return true;

//     lcaofnode.pop_back();
//     return false;
//  }
// bool finddistnodes(TreeNode* root,TreeNode* target,int distance,int& nodeval){
//     if(root==nullptr || root->val==target->val)
//         return false;
    
//     if(distance==0 && root){
//         nodeval=root->val;
//         return true;
//     }
//     if(finddistnodes(root->left,target,distance-1,nodeval) || finddistnodes(root->right,target,distance-1,nodeval)){
//         return true;
//     }
//     return false;
// }
void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track,TreeNode* target){
    queue<TreeNode*> q;
    q.push(root);

    while (not(q.empty()))
    {
        TreeNode* current=q.front();
        q.pop();

        if(current->left){
            parent_track[current->left]=current;
            q.push(current->left);
        }

        if(current->right){
            parent_track[current->right]=current;
            q.push(current->right);
        }
    }
}
bool oneSegment(string str){
    //we find if str contains <=1 contiguous segment of ones
    int s=0,e=0,numsegments=0,n=str.length();

    while (true)
    {
        while (str[e]!='0' && e<n)
        {
            e++;
        }
        if(e==n){
            if(e>s)
                numsegments++;
            break;
        }

        if(e>s){
            numsegments++;
            s=e;
        }
        else{
            s++;
            e=s;
        }
    }
    //cout<<numsegments<<endl;

    if(numsegments>1)
        return false;
    return true;
}
int countRectangles(int n){
    long long totalsqandrecs=((((n+1)*n)%M)/2)*((((n+1)*n)%M)/2);
    long long numsquares=((((n*(n+1))%M)*(2*n+1))%M)/6;


    return totalsqandrecs-numsquares;
}
int factorials(int num){
    int fact=1;

    while (num)
    {
        fact=(fact*num)%M;
        num--;
    }
    return fact;
}