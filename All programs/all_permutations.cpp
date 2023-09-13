#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void allpermutations(vector<int>,vector<int>);


int main(){
    vector<int> perm={1,2,3},v;
    allpermutations(perm,v);
    return 0;
}
void allpermutations(vector<int> perm,vector<int> perm_holder){
    if (perm.size()==0){
        for(auto item:perm_holder)
            cout<<item<<" ";
        cout<<endl;
        return;
    }
    
    for(int i=0;i<perm.size();i++){
        vector<int> prev=perm_holder;
        perm_holder.push_back(perm[i]);
        
        vector<int> new_perm;
        for(int j=0;j<i;j++)
            new_perm.push_back(perm[j]);
        for(int j=i+1;j<perm.size();j++)
            new_perm.push_back(perm[j]);
        allpermutations(new_perm,perm_holder);
        perm_holder=prev;
    }
}