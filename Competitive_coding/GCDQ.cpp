#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int gcd(int,int);

int main(){
    int t;
    cin>>t;
    // cout<<gcd(36,60)<<endl;
    while(t--){
        int n,q;
        cin>>n>>q;
        int a[n+10],forward[n+10],backward[n+10];
        forward[0]=backward[n+1]=0;


        for(int i=1;i<=n;i++){                   //for pre-computation always use 1 based indexes in array
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            forward[i]=gcd(forward[i-1],a[i]);
        }
        for(int i=n;i>=1;i--){
            backward[i]=gcd(backward[i+1],a[i]);
        }

        // for(int i=1;i<=n;i++)
        //     cout<<forward[i]<<" ";
        // cout<<endl;

        // for(int i=n;i>=1;i--)
        //     cout<<backward[i]<<" ";
        // cout<<endl;


        while (q--)
        {
            int l,r;
            cin>>l>>r;
            int gc=0;
            // for(int i=1;i<l;i++){
            //     gc=gcd(gc,a[i]);
            // }
            // for(int i=r+1;i<=n;i++){
            //     gc=gcd(gc,a[i]);
            // }
            cout<<gcd(forward[l-1],backward[r+1])<<endl;
        }
    }
    return 0;
}
//Brute force T(N)=O(T*(N+Q*N))=O(T*N+T*N*Q)=O(T*N*Q)
/*Precomputation T(N)=O(T*(N+N))=O(T*N)*/
int gcd(int num1,int num2){
    if(num1%num2==0 || num1==0)
        return num2;

    if(num1<num2)
       swap(num1,num2);

    return gcd(num2,num1%num2);
}