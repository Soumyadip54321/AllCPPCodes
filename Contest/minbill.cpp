#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
long long totalBill(int n, vector<int>& a);
string encodeString(string &s, int n); 
int minimumDistancePairs(int n, vector<int> &arr);
int longestNinjaPath(int n, vector<int> &arr);

int main(){
    vector<int> a={2, 3, 5, 1};
    string s="abc";
    //vector<int> arr={-2,0,2};
    vector<int> arr={10,20,10,30,40};
    //cout<<minimumDistancePairs(3,arr);
    //cout<<totalBill(4,a);
    //cout<<encodeString(s,3);
    cout<<longestNinjaPath(5,arr);
    return 0;
}
long long totalBill(int n, vector<int>& a){
    int turnnegative=a[0],negidx=0;
    long long minsum=0;

    for(int i=1;i<n;i++){
        if(abs(a[i])>abs(turnnegative)){
            turnnegative=a[i];
            negidx=i;
        }
    }

    a[negidx]=-1*a[negidx];
    for(auto val:a)
        minsum+=val;

    return minsum;
}
string encodeString(string &s, int n){
    string ans="";

    for(int i=0;i<n;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            ans+=s[i]+1;
        }
        else{
            ans+=s[i]-1;
        }
    }
    return ans;
}
int minimumDistancePairs(int n, vector<int> &arr){
    //we sort at first
    int mindist=INT_MAX,ct=0;
    sort(arr.begin(),arr.end());

    for(int i=n-1;i>0;i--){
        mindist=min(mindist,arr[i]-arr[i-1]);
    }
    //cout<<mindist<<endl;

    for(int i=n-1;i>0;i--){
        if(arr[i]-arr[i-1]==mindist)
            ct++;
    }
    return ct;
}
int longestNinjaPath(int n, vector<int> &arr){
    //we find num of sign changes
    vector<char> signs,buildingsjumped;
    int start=0,end=1;
    char nature;

    for(int i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]<0)
            signs.push_back('-');
        else if(arr[i+1]>arr[i])
            signs.push_back('+');
        else
            signs.push_back('o');
    }

    for(auto ch:signs)
        cout<<ch<<",";
    cout<<endl;

    nature=signs[0];
    buildingsjumped.push_back(arr[0]);
    buildingsjumped.push_back(arr[1]);

    for(end=1;end<signs.size();end++){
        if(signs[end]=='-' and nature=='+'|| signs[end]=='-' and nature=='+'){
            maxjumps++;
            nature=signs[end];
        }
    }
    return maxjumps;
}