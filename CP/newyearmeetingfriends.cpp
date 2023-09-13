#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int findmeetpoint(int,int,int);

int main(){
    int x1,x2,x3;
    cin>>x1>>x2>>x3;
    cout<<findmeetpoint(x1,x2,x3)<<endl;
    return 0;
}
int findmeetpoint(int x1,int x2,int x3){
    //we apply binary search here
    vector<int> xcoord={x1,x2,x3};
    sort(xcoord.begin(),xcoord.end());
    
    return abs(xcoord[1]-xcoord[0])+abs(xcoord[2]-xcoord[1]);
}