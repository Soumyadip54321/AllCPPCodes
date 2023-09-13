#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class BinaryTreeNode 
{
    public:

	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
int deepestLeftLeafNode(BinaryTreeNode* root);

int main(){
    // BinaryTreeNode* root=new BinaryTreeNode(9);
    // root->left=new BinaryTreeNode(18);
    // root->right=new BinaryTreeNode(16);
    // root->left->left=new BinaryTreeNode(2);
    // root->left->right=new BinaryTreeNode(27);
    // root->right->right=new BinaryTreeNode(27);
    // root->left->left->left=new BinaryTreeNode(9);
    // root->left->left->right=new BinaryTreeNode(5);
    // root->left->right->left=new BinaryTreeNode(6);
    // root->left->right->right=new BinaryTreeNode(23);
    // root->left->left->left->left=new BinaryTreeNode(17);
    // root->left->left->right->right=new BinaryTreeNode(10);
    // root->left->right->right->left=new BinaryTreeNode(14);
    // root->left->left->left->left->right=new BinaryTreeNode(7);
    // root->left->right->right->left->left=new BinaryTreeNode(4);
    // root->left->right->right->left->left->right=new BinaryTreeNode(13);
    // root->left->left->left->left->right->right=new BinaryTreeNode(30);
    // root->left->left->left->left->right->right->left=new BinaryTreeNode(2);

     BinaryTreeNode* root=new BinaryTreeNode(10);
    root->left=new BinaryTreeNode(23);
    root->right=new BinaryTreeNode(15);
    root->left->left=new BinaryTreeNode(4);
    root->right->left=new BinaryTreeNode(17);
    root->right->right=new BinaryTreeNode(11);
    root->left->left->left=new BinaryTreeNode(27);
    root->right->left->right=new BinaryTreeNode(24);
    root->left->left->left->left=new BinaryTreeNode(7);
    root->right->left->right->right=new BinaryTreeNode(6);
    root->right->left->right->right->left=new BinaryTreeNode(28);

    cout<<deepestLeftLeafNode(root)<<endl;
    return 0;
}
int deepestLeftLeafNode(BinaryTreeNode* root){
    /*
    idea:
    1.  we maintain a queue to put nodes into
    2. we also keep a variable that acts as a keeper of current deepest left leaf node
    3. when at a level we keep in the variable the leftmost node
    */
   queue<BinaryTreeNode*> q;
   pair<BinaryTreeNode*,int> leftdeepest;
   int level=0;

   q.push(root);
   leftdeepest={root,0};

   while (not(q.empty()))
   {
        int size=q.size();
        level++;

        for(int i=0;i<size;i++){
            BinaryTreeNode* node=q.front();
            q.pop();

            if(node->left && level>leftdeepest.second){
                leftdeepest.first=node->left;
                leftdeepest.second=level;
            }

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
   }
    if(leftdeepest.first==root)
        return 0;

   return leftdeepest.first->data;
}