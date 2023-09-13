#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int countSubarrays(int n, vector<int> arr);

int main(){
    vector<int> arr={1,0,2,1,0,2};
    cout<<countSubarrays(6,arr);
    return 0;
}
int countSubarrays(int n, vector<int> arr){
    //naive approach first we find all subarrays
    //i.e. include only items containing 0,1, and 2
    bool zeroct=false,onect=false,twoct=false;
    int a[]={1,1,1},equalct=0;

    for(auto val:arr){
        if(val==0)
            zeroct=true;
        if(val==1)
            onect=true;
        if(val==2)
            twoct=true;
    }

    if(not(zeroct && onect && twoct))
        return 0;
    int p1=0,lastoccuramongonezertwo,i=n,p2=n-1,jump=3;

    while (a[0]!=0 || a[1]!=0 || a[2]!=0)
    {
        i--;
        if(a[arr[i]])
            a[arr[i]]--;
    }
    lastoccuramongonezertwo=i;

    while (p1<=lastoccuramongonezertwo)
    {
        int numzero=0,numone=0,numtwo=0;
        vector<int> v;
        for(int j=p1;j<p1+jump;j++){
            if(arr[j]==1)
                numone++;
            if(arr[j]==0)
                numzero++;
            if(arr[j]==2)
                numtwo++;
            v.push_back(arr[j]);
        }
        if(numone==numtwo && numone==numzero && numzero==numtwo)
            equalct++;

        jump++;

        if(jump+p1>n){
            jump=3;
            p1++;
        }
    }
    return equalct;
}