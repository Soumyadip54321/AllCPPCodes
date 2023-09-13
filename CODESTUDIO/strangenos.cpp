#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int strangeNumbers(int n);

const int n=1e5+1;

int main(){
    cout<<strangeNumbers(899);
}
int strangeNumbers(int n){
    unordered_map<int,pair<bool,int>> validinvaliddigits;
    int numstrange=0;

    for(int i=0;i<10;i++){
        if(not(i==2 || i==3 || i==4 || i==5 || i==7)){
            if(i==0 || i==1 || i==8)
                validinvaliddigits[i]={true,i};
            else{
                if(i==6)
                    validinvaliddigits[i]={true,9};
                else
                    validinvaliddigits[i]={true,6};
            }
        }
        else
            validinvaliddigits[i]={false,-1};    
    }

    int p=min(9,n);
    for(int i=1;i<=p;i++){
        if(validinvaliddigits[i].first && validinvaliddigits[i].second!=i)
            numstrange++;
    }

    for(int i=10;i<=n;i++){
        string str=to_string(i);
        bool isvalid=true;

        for(int j=0;j<str.length();j++){
            if(not(validinvaliddigits[str[j]-'0'].first)){
                isvalid=false;
                break;
            }
        }
        if(isvalid){
            reverse(str.begin(),str.end());
            if(stoi(str)!=i)
                numstrange++;
        }
    }

    return numstrange;
}