#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int gap(int n, int k, vector<int>&a);
int findsum(vector<int>,int,int);


int main(){
    vector<int> a={7, 8, 7, 3, 8, 6, 4, 10, 9, 1, 8, 10, 10, 6, 7, 10, 8};
    cout<<gap(17,8,a)<<endl;
    return 0;
}
int gap(int n, int k, vector<int>&a){
    int mindiff=1e9+10,start=0,end=0,prev=mindiff;
    vector<int> temp=a;

    if(k==0)
        return *max_element(a.begin(),a.end())-*min_element(a.begin(),a.end());
    
    for(int st=n-1;st>=k-1;st--){
        mindiff=min(mindiff,findsum(temp,st,k));
        if(mindiff<prev){
            start=st;
            end=st-k+1;
            prev=mindiff;
        }
    }
    //cout<<"start index: "<<start<<" end index: "<<end<<endl;
    // a.erase(a.begin()+end,a.begin()+start+1);

    // for(auto val:a)
    //     cout<<val<<" ";
    // cout<<endl;

    // return *max_element(a.begin(),a.end())-*min_element(a.begin(),a.end());
    return mindiff;
}
int findsum(vector<int> temp,int st,int k){
    temp.erase(temp.begin()+st-k+1,temp.begin()+st+1);

    return *max_element(temp.begin(),temp.end())-*min_element(temp.begin(),temp.end());
}
