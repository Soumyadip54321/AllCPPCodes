#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int largestSquareSubmatrix(vector<vector<int>> &mat, int n, int m, int k);

int main(){
    vector<vector<int>> mat={{1,0,3},{0,1,5},{4,4,5}};
    cout<<largestSquareSubmatrix(mat,3,3,2);
    return 0;
}
int largestSquareSubmatrix(vector<vector<int>> &mat, int n, int m, int k){
    int rl=n-1,rh=0,cl=0,ch=m-1;
    vector<int> colsum(m,0),rowsum(n,0);
    int csum=0,rsum=0;

    //fill row
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            rowsum[r]+=mat[r][c];
        }
    }
    //fill col
    for(int c=0;c<m;c++){
        for(int r=0;r<n;r++){
            colsum[c]+=mat[r][c];
        }
    }
    //fill csum and rsum
    for(int i=0;i<m;i++)
        csum+=colsum[i];

    rowsum=colsum;


    //now we traverse first across col & then row-wise
    int csize=ch-cl+1;
    




}