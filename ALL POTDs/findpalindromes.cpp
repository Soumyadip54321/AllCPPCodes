#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getPalindromes(int n);
bool ispalin(int);

int main(){
    vector<int> res;
    res=getPalindromes(35);
    return 0;
}
vector<int> getPalindromes(int n){
    vector<int> res;

    if(n<10){
        for(int i=1;i<=n;i++)
            res.push_back(i);
        return res;
    }

    for(int i=1;i<=9;i++)
        res.push_back(i);

    for(int i=10;i<=n;i++){
        if(ispalin(i))
            res.push_back(i);
    }

    // for(auto val:res)
    //     cout<<val<<",";
    // cout<<endl;

    return res;
}
bool ispalin(int num){
    int len=ceil(log(num)/log(10));
    int ans=0;

    for(int i=0;i<len/2;i++){
        ans=ans*10+num%10;
        num/=10;
    }
    if(len%2==1){
        ans=ans*10+num%10;
    }
    return ans==num;
}