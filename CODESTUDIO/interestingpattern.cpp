#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<char>> interestingPattern(int n);

int main(){
    vector<vector<char>> pattern;
    pattern=interestingPattern(4);
    return 0;
}
vector<vector<char>> interestingPattern(int n){
    vector<vector<char>> p;
    int total=n;
    string alphabet="",prev="";

    for(int i=0;i<n;i++){
        alphabet+='A'+i;
    }

    while (n)
    {
        vector<char> ch;
        for(int i=n-1;i<total;i++){
            ch.push_back(alphabet[i]);
        }
        p.push_back(ch);
        n--;
    }
    
    // for(int i=0;i<p.size();i++){
    //     for(auto entry:p[i])
    //         cout<<entry;
    //     cout<<endl;
    // }

    // cout<<alphabet<<endl;
    return p;
}