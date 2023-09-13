#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool validStackPermutation(vector<int> &first, vector<int> &other);

int main(){
    vector<int> first={2,4,6},other={2,6,4};
    cout<<validStackPermutation(first,other);
    return 0;
}
bool validStackPermutation(vector<int> &first, vector<int> &other){
    int n1=first.size(),n2=other.size();
    unordered_map<int,bool> m;

    if(n1!=n2)
        return false;
    
    for(int i=0;i<n1;i++){
        m[first[i]]=true;
    }

    for(int i=0;i<n2;i++){
        if(not(m[other[i]]))
            return false;
    }

    
    return true;
}