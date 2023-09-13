#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define SIZE 10
using namespace std;

int beautifulmtx(vector<vector<int>>);

int main(){
    vector<vector<int>> mtx(5,vector<int>(5,0));

    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            cin>>mtx[r][c];
        }
    }
    cout<<beautifulmtx(mtx)<<endl;
    return 0;
}
int beautifulmtx(vector<vector<int>> mtx){
    //size is fixed at 5 by 5
    int n=5;
    bool found=false;
    int rmid=2,cmid=2,rloc1,cloc1,minmoves=0;

    //we find loc of 1 first
    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            if(mtx[r][c]==1){
                rloc1=r;
                cloc1=c;
                found=true;
                break;
            }
        }
        if(found)
            break;
    }
    return abs(rloc1-rmid)+abs(cloc1-cmid);
}