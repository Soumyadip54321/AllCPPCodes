#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<string>find_permutation(string S);


int main(){
    vector<string> allperm;
    string str="ABSG";
    allperm=find_permutation(str);
    return 0;
}
vector<string>find_permutation(string S){
    vector<string> p;
    sort(S.begin(),S.end());

    do{
        p.push_back(S);
    }while(next_permutation(S.begin(),S.end()));

    for(auto str:p)
        cout<<str<<",";
    cout<<endl;
    return p;
}