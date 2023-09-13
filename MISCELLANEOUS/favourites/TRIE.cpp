#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct NODE
{
    NODE* arr[26];
    bool flag=false;

    bool containskey(char ch){
        if(arr[ch-'a'])
            return true;
        return false;
    }
};

NODE* root=new NODE();

void insert(string);
bool search(string);


int main(){
    string str="coding";
    insert(str);
    insert("ninjas");
    // insert("mango");
    // insert("pineapple");
    // insert("carrot");

    cout<<search("coding");
    cout<<search("code");
    cout<<search("ninjas");
    return 0;
}
void insert(string str){
    NODE* curr=root;

    for(int i=0;i<str.length();i++){
        if(not(curr->containskey(str[i]))){
            curr->arr[str[i]-'a']=new NODE();       //creating reference TRIES
        }
        curr=curr->arr[str[i]-'a'];
    }
    curr->flag=true;    //setting flag=true for the last refrence TRIE formed
}
bool search(string s){
    NODE* curr=root;
    int i=0;

    while (curr->arr[s[i]-'a'] && i<s.length())
    {
        curr=curr->arr[s[i]-'a'];
        i++;
    }
    return curr->flag;
}