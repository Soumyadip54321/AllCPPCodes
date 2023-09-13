#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int arrayOperations(int n, vector<int> &arr);
int numpartitions(vector<int>,int,int,int);
vector<vector<int>> generateMatrix(int n);
void display(int**,int);
vector<vector<int>> arraytovector(int**,int);


int main(){
    vector<int> arr={0,2,0,5,6,3,0,0,1};
    vector<vector<int>> spiral;
    // cout<<arrayOperations(9,arr)<<endl;
    spiral=generateMatrix(20);

    for(int i=0;i<20;i++){
        for(auto item:spiral[i])
            cout<<item<<" ";
        cout<<endl;
    }
    return 0;
}
int arrayOperations(int n, vector<int> &arr){
    /*first we count whether 0 present*/
    int present=0,divisions=0;
    if(find(arr.begin(),arr.end(),0)-arr.begin()>=n)
        return -1;
    
    /*here we check whether atleast one non-zero element present*/
    for(auto item:arr){
        if(item>0){
            present=1;
            break;
        }
    }
    if(present==0)
        return 0;
    /*2nd approach*/
    for(int i=1;i<n;i++){
        if(arr[i-1]>0 && arr[i]==0)
            divisions+=1;
    }
    if(arr[n-1]>0)
        return 1+divisions;
    return divisions;
    // if(present==1)
    //     return 1+numpartitions(arr,n-1,0,0);
}
int numpartitions(vector<int> arr,int idx,int regions,int posmark){
    if(idx==0)
        return regions;

    if(arr[idx]>0)
        posmark=1;
    
    if(posmark==1 && arr[idx]==0){
        regions++;
        posmark=0;
    }
    return numpartitions(arr,idx-1,regions,posmark);
}
vector<vector<int>> generateMatrix(int n){
    int hrow=0,hcol=n-1,lrow=n-1,lcol=0,num=0;

    int** spiral=new int*[n];
    for(int i=0;i<n;i++){
        spiral[i] = new int[n];
        for(int j=0;j<n;j++)
            spiral[i][j]=0;
    }
    while(hrow<=lrow && lcol<=hcol){
        if(lcol<=hcol){
            for(int i=lcol;i<=hcol;i++){
                num++;
                spiral[hrow][i]=num;
                
            }
        }
        hrow++;

        if(hrow<=lrow){
            for(int i=hrow;i<=lrow;i++){
                num++;
                spiral[i][hcol]=num;
            }
        }
        hcol--;
        if(lcol<=hcol){
            for(int i=hcol;i>=lcol;i--){
                num++;
                spiral[lrow][i]=num;
            }
        }
        lrow--;
        if(hrow<=lrow){
            for(int i=lrow;i>=hrow;i--){
                num++;
                spiral[i][lcol]=num;
            }
            
        }
        lcol++;
    }
    return arraytovector(spiral,n);
}
void display(int** spiral,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<spiral[i][j]<<" ";
        cout<<endl;
    }
}
vector<vector<int>> arraytovector(int** spiral,int n){
    vector<vector<int>> spiralmatrix;
    vector<int> elements;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            elements.push_back(spiral[i][j]);
        }
        spiralmatrix.push_back(elements);
        elements.clear();
    }
    return spiralmatrix;
}