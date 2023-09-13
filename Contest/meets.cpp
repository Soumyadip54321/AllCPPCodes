#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

long long meetThem(long long A, long long B, long long C);
long long lcm(long long,long long);
long long gcd(long long,long long);
int minimumWaitTime(int N, int M, int C, vector<int> &arr);



int main(){
    long long int A=5,B=10,C=23;
    int n=4,m=3,c=3;
    vector<int> arr={5,3,7,8};
    // cout<<meetThem(A,B,C)<<endl;
    cout<<minimumWaitTime(n,m,c,arr)<<endl;
    return 0;
}
long long meetThem(long long A, long long B, long long C){
    return C/lcm(A,B);
}
long long lcm(long long A,long long B){
    if(A<B)
        swap(A,B);
    return (A*B/gcd(A,B));
}
long long gcd(long long A,long long B){
    if(B==0)
        return A;
    if(A%B==0 || A==0)
        return B;
    
    return gcd(B,A%B);
}
int minimumWaitTime(int N, int M, int C, vector<int> &arr){
    int **hsh=new int*[N];

    for(int i=0;i<N;i++){
        hsh[i]=new int [N];
        for(int j=0;j<N;j++)
            hsh[i][j]=0;
    }

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            hsh[i][j]=abs(-1*arr[j]+arr[i]);
        }
    }

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++)
            cout<<hsh[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

