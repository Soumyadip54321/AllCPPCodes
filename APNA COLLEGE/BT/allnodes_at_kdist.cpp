#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
bool findnode(node*,node*&,int);
void subtreenodes(node*,int);
void inorder(node*);
void ancestorsearch(node*,node*,int);
bool LCA(node*,int,vector<int>&);
void searchfromroot(node*,node*,int);
bool targetposition(node*,int);


int main(){
    node *root=new node(1);
    root->left=new node(5);
    root->right=new node(2);
    root->left->left=new node(6);
    root->right->left=new node(3);
    root->right->right=new node(4);
    root->left->left->right=new node(7);
    root->left->left->right->left=new node(8);
    root->left->left->right->right=new node(9);

    inorder(root);

    node* targetnode=nullptr;
    if(findnode(root,targetnode,5)){
        cout<<"\nfound node in tree"<<endl;
        //cout<<targetnode->data;
        cout<<"node at distance 3 are:"<<endl;
        subtreenodes(targetnode,3);
    }
    else
        cout<<"couldn\'t find node in tree"<<endl;
    ancestorsearch(root,targetnode,3);
    //inorder(root);
    return 0;
}
//first we look for the node to start at in tree
bool findnode(node* root,node*& targetnode,int nodeval){
    if(root->data==nodeval){
        targetnode=root;
        return true;
    }
    if(findnode(root->left,targetnode,nodeval) || findnode(root->right,targetnode,nodeval)){
        return true;
    }
    return false;   
}

void searchfromroot(node* root,node* targetroot,int k){
    if(root==nullptr || k<0)
        return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    searchfromroot(root->left,targetroot,k-1);
    searchfromroot(root->right,targetroot,k-1);
}

//case 1:search in subtree 
void subtreenodes(node* targetnode,int k){
    if(k<0 || targetnode==nullptr)
        return;
    
    if(k==0){
        cout<<targetnode->data<<" ";
        return;
    }
    subtreenodes(targetnode->left,k-1);
    subtreenodes(targetnode->right,k-1);
}

//case 2:search in tree through ancestor
/*1. here we find LCA of target node
  2. Then we compute the path distance
  3. 2 cases arises:
        (i) path length >= k: we print the node(ancestor) present in the path
        (ii) else we compute the balance distance and repeat subtreesearch from the root
*/

void ancestorsearch(node* root,node* targetnode,int k){
    /*first we find path to targetnode from root*/
    vector<int> p;
    if(LCA(root,targetnode->data,p)==false)
        return;                                 //indicates our targetnode is root and we already figured out all node at k distance from it
    
    /*we compute k-path length to find if we do need to look for from the root to the other subtree*/
    // if(k-(p.size()-1)<=0){
    //     cout<<" "<<p[p.size()-1-k];
    //     return;
    // }
    //cout<<k-(p.size()-1)<<endl;

    /*here we look in the right subtree if targetnode lies in left subtree
    else we search in left*/
    if(targetposition(root->left,targetnode->data)){
        searchfromroot(root->right,targetnode,k-(p.size()-1)-1);
        return;
    }
    searchfromroot(root->left,targetnode,k-(p.size()-1)-1);
}
void inorder(node* root){
    if(root==nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool LCA(node* root,int nodeval,vector<int>& path){
    /*idea: 
    1.  we try and compute the LCA of the given node in BT*/
    if(root==nullptr)           //base condition
        return false;
    path.push_back(root->data);

    if(root->data==nodeval){
        return true;
    }
    
    if(LCA(root->left,nodeval,path) || LCA(root->right,nodeval,path))
        return true;
    path.pop_back();
    return false;
}
bool targetposition(node* root,int targetval){
    if(root==nullptr)
        return false;

    if(root->data==targetval)
        return true;
    
    if(targetposition(root->left,targetval) || targetposition(root->right,targetval))
        return true;
    return false;
}
