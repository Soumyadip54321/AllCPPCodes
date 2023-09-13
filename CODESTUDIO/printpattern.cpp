#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> printPattern(int n);
int pattern[200][200];

int main(){
    vector<string> v;
    v=printPattern(4);
    return 0;
}
vector<string> printPattern(int n){
    int rowh=0,rowl=n-1,coll=0,colh=n,times=n;
    int num=1;
    vector<string> s;
    while (times)
    {
        for(int i=coll;i<colh;i++){
            pattern[rowh][i]=num;
            num++;
        }
        rowh++;

        times--;
        if(times==0)
            break;

        for(int i=coll;i<colh;i++){
            pattern[rowl][i]=num;
            num++;
        }
        rowl--;
        times--;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<pattern[i][j]<<",";
    //     }
    //     cout<<endl;
    // }

    for(int i=0;i<n;i++){
        string ans="";
        for(int j=0;j<n;j++){
            ans+=to_string(pattern[i][j]);
            ans+=' ';
        }
        s.push_back(ans);
    }

    // for(int i=0;i<n;i++){
    //     for(auto ch:s[i]){
    //         cout<<ch<<" ";
    //     }
    //     cout<<endl;
    // }
    return s;
}