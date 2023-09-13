#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int finddrinksmadebyeach(int,int,int,int,int,int,int,int);


int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    cout<<finddrinksmadebyeach(n,k,l,c,d,p,nl,np);
    return 0;
}
int finddrinksmadebyeach(int n,int k,int l,int c,int d,int p,int nl,int np){
    int totaldrinkspossible;
    totaldrinkspossible=min((k*l)/nl,min((p/np),d*c));

    return totaldrinkspossible/n;
}