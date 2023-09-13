#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> letterCombinations(string digits);
void combinations(string,vector<string>&,string,int);
unordered_map<int,string> m={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};


int main(){
    string digits="";
    vector<string> ans;
    ans=letterCombinations(digits);
    return 0;
}
vector<string> letterCombinations(string digits){
    vector<string> ans;
    string s;
    int n=digits.length();

    if(n==0)
        return ans;

    combinations(digits,ans,s,0);

    for(auto s:ans)
        cout<<s<<",";
    cout<<endl;

    return ans;
}
void combinations(string digits,vector<string>& ans,string comb,int idx){

    if(comb.length()==digits.length()){
        ans.push_back(comb);
        return;
    }
    string prev=comb;
    for(int i=0;i<m[digits[idx]-'0'].length();i++){
        combinations(digits,ans,comb+m[digits[idx]-'0'][i],idx+1);
        comb=prev;
    }
}