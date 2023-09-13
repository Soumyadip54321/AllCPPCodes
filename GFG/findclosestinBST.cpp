#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int minDiff(Node *root, int K);
void sorteditems(Node*);
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

vector<int> elements;


int main(){
    Node* pre;
    Node* suc;

    Node* root=new Node(8);
    root->left=new Node(1);
    root->right=new Node(9);
    //root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->left->right->left=new Node(3);
    root->right->right=new Node(10);
    //root->left->right->left->right=new Node(4);

    findPreSuc(root,pre,suc,11);
    cout<<pre->data<<" "<<suc->data<<endl;
    //cout<<minDiff(root,9)<<endl;
    return 0;
}
int minDiff(Node *root, int K){
    /*idea: 1. Consider values in inorder in an array
            2. find diff from each element
            3. return the largest
    */
   int leastabsdiff=INT_MAX;
   sorteditems(root);

   for(auto val:elements){
    leastabsdiff=min(leastabsdiff,abs(val-K));
   }
    return leastabsdiff;
}
void sorteditems(Node* root){
    if(root==nullptr)
        return;
    
    sorteditems(root->left);
    elements.push_back(root->data);
    sorteditems(root->right);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){

    /*
        naive approach:
        1. consider inorder elements inclusion in an array
        2. apply binary search to find position of key
        3. check for elements preceeding and succeeding it in array
    */

    /*
        TC=O(height of BST)+O(LOG(height of BST))
        WHERE N:- number of nodes
        SC=O(height of BST)
    */
  sorteditems(root);
  int low=0,high=elements.size()-1;
  while (high-low>1)
  {
    int mid=low+(high-low)/2;
    if(elements[mid]<key)
        low=mid;
    else{
        high=mid;
    }
  }
  /*WHEN KEY ABSENT IN BST*/
    if(elements[high]<key && elements[low]<key){
        pre=new Node(elements[high]);
        suc=new Node(-1);
        return;
    }
    else if(elements[high]>key && elements[low]>key){
        suc=new Node(elements[low]);
        pre=new Node(-1);
        return;
    }

    /*WHEN KEY PRESENT IN BST*/
    if(elements[high]==key){
        if(high+1>=elements.size())
            suc=new Node(-1);
        else
            suc=new Node(elements[high+1]);
        pre=new Node(elements[low]);
        return;
    }

    if(elements[low]==key){
        if(low-1<0)
            pre=new Node(-1);
        else
            pre=new Node(elements[low-1]);
        suc=new Node(elements[low]);
        return;
    }
    pre=new Node(elements[low]);
    suc=new Node(elements[high]);
    return;
}