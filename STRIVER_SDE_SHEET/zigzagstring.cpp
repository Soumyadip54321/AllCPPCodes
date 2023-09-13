#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string zigZagString(string str, int n, int m);

int main(){
    string str="A";
    cout<<zigZagString(str,1,1);
    return 0;
}
string zigZagString(string str, int n, int m){
    vector<vector<char>> pattern(m,vector<char>(1000));
    string ans;
    int rh=0,rl=m-1,idx=0;

    while (idx<n)
    {
        for(int i=rh;i<=rl;i++){
            pattern[i].push_back(str[idx]);
            if(idx==n)
                break;
            idx++;
        }
        rh=0;

        for(int i=rl-1;i>rh;i--){
            pattern[i].push_back(str[idx]);
            if(idx==n)
                break;

            idx++;
        }
        rl=m-1;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<pattern[i].size();j++){
            if(pattern[i][j])
                ans+=pattern[i][j];
        }
    }
    return ans;
}