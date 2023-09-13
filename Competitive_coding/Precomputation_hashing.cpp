#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

//given an array of N integers and Q queries with a number in each. Print count of that number in array.
//constraints:
/*1<=N<=10^5*/
/*1<=A[I]<=10^7*/
/*1<=Q<=10^5*/
const int N=1e7+10;
int hash_array[N];


int main(){
    int n;
    cin>>n;
    int arr[n];
    //Now we perform the same with hashing a.k.a pre-computation technique
    for(int i=0;i<n;i++){
        cin>>arr[i];
        hash_array[arr[i]]++;
    }
    int q;
    cin>>q;
    while(q--){                                 //Time complexity of this code: T(n)=O(N)+O(Q*N)=O(N^2)    /*Time complexity of hashed code T(N)=O(N)+O(Q)=O(N)*/
        int x;
        cin>>x;
        cout<<hash_array[x]<<endl;
    }
    return 0;
}