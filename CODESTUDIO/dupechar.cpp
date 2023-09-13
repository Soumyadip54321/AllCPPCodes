#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<pair<char,int>> duplicate_char(string s, int n);
const int N=1e5+10;
int chararr[N];

int main(){
    vector<pair<char,int>> v;
    string s="gsddzvwkykahecjj";
    v=duplicate_char(s,16);
    return 0;
}
vector<pair<char,int>> duplicate_char(string s, int n){
    //map<char,int> dupes;
    vector<pair<char,int>> v;
    for(int i=0;i<n;i++){
        chararr[s[i]-'A']++;
    }

    for(int i=0;i<N;i++){
        if(chararr[i]>=2){
            v.push_back({'A'+i,chararr[i]});
            chararr[i]=0;
        }
    }
    // for(auto p:v){
    //     cout<<p.first<<":"<<p.second<<endl;
    // }
    for(int i=0;i<N;i++)
        chararr[i]=0;
    return v;
}