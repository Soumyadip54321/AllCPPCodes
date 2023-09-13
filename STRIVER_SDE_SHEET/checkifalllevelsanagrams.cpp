#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class TreeNode {
public :
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this -> val = val;
        left = NULL;
        right = NULL;
    }
};
bool anagram(TreeNode *root1, int n, TreeNode *root2, int m);
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(11);
    root->left->right=new TreeNode(12);
    root->right->left=new TreeNode(7);
    root->right->left->left=new TreeNode(4);
    root->right->left->right=new TreeNode(9);
    // root->right->right=new TreeNode(4);

    TreeNode* root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);
    root2->left->left=new TreeNode(12);
    root2->right->left=new TreeNode(11);
    root2->right->right=new TreeNode(7);
    root2->right->left->left=new TreeNode(9);
    root2->right->right->right=new TreeNode(6);
    // root2->left->right=new TreeNode(5);

    cout<<anagram(root,8,root2,8);
    return 0;
}
bool anagram(TreeNode *root1, int n, TreeNode *root2, int m){
    if(n!=m)
        return false;
    
    //we apply BFS here for both trees at a time
    /*
    idea:
    1.  at every level we first check for num nodes, if unequal we return false
    2. else we keep an unordered map to put value at node & its frequency in one tree
    3. Againt that we check occurence of same value in the other  
    */
    queue<TreeNode*> q1,q2;
    

    q1.push(root1);
    q2.push(root2);

    while (not(q1.empty()) && not(q2.empty()))
    {
        int s1=q1.size();
        int s2=q2.size();

        if(s1!=s2)
            return false;
        
        unordered_map<int,int> m1;
        //bfs in tree1
        for(int i=0;i<s1;i++){
            TreeNode* n1=q1.front();
            q1.pop();

            m1[n1->val]++;

            if(n1->left)
                q1.push(n1->left);
            if(n1->right)
                q1.push(n1->right);
        }

        //bfs in tree2
        for(int i=0;i<s2;i++){
            TreeNode* n2=q2.front();
            q2.pop();

            if(not(m1[n2->val]))
                return false;

            if(n2->left)
                q2.push(n2->left);
            if(n2->right)
                q2.push(n2->right);
        }
    }

        return true;
}