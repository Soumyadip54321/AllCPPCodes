#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define MAX 1000
using namespace std;

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main(){
    int M[MAX][MAX] = {{0, 0, 0, 1},{0, 0, 0, 1}};
    vector<vector<int>> uniquerows;
    uniquerows=uniqueRow(M,2,4);
    return 0;
}
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col){
    vector<string> v;
    vector<vector<int>> urows;
    unordered_map<string,int> m;
    
    for(int r=0;r<row;r++){
        string num="";
        for(int c=0;c<col;c++){
            num+=to_string(M[r][c]);
        }
        v.push_back(num);
        m[num]++;
    }

    for(auto str:v){
        if(m[str]>0){
            vector<int> ur;
            for(int i=0;i<str.length();i++){
                ur.push_back(str[i]-'0');
            }
            urows.push_back(ur);
            m[str]=0;
        }
    }

    // for(int i=0;i<urows.size();i++){
    //     for(auto val:urows[i])
    //         cout<<val<<",";
    //     cout<<endl;
    // }
    return urows;
}