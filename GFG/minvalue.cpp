#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

long long int minValue(int a[], int b[], int n);
int maxLen(vector<int>&A, int n);

int main(){
    int a[]={3,1,1},b[]={6,5,4};
    vector<int> A={15,-2,2,-8,1,7,10,23};
    //cout<<minValue(a,b,3)<<endl;
    cout<<maxLen(A,8)<<endl;
    return 0;
}
long long int minValue(int a[], int b[], int n){
    sort(a,a+n,greater<int>());
    sort(b,b+n);

    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i]*1LL*b[i]*1LL;
    }
    return sum;
}
int maxLen(vector<int>&A, int n){
    unordered_map<int,pair<int,int>> m;
    A.insert(A.begin(),0);
    int maxlen=-1;

    for(int i=1;i<=n;i++){
        A[i]+=A[i-1];
    }
    for(auto val:A)
        cout<<val<<",";
    cout<<endl;

    for(int i=0;i<=n;i++){
        m[A[i]].second=i;       /*containg ending index*/
    }

    for(int i=n;i>=0;i--){
        m[A[i]].first=i;            /*contains starting index*/
    }

    for(int i=0;i<m.size();i++){
        maxlen=max(maxlen,m[A[i]].second-m[A[i]].first);
    }
    return maxlen;
}
