#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int minDeletions(string str);

const int n=1e5+10;


int main(){
    string str="yhcowdfqlwfidnxltfiujithubvyzjwhwadenepvvlliqnavethpudegquvfwecillnrscumkdtfogddogemxtdohwpodbn";
    cout<<minDeletions(str);
    return 0;
}
int minDeletions(string str){
    //we maintain an array with indices as frequency and corresponding value as number of unique letters each occuring index times
    int len=str.length(),mindeletes=0,maxfreq=-1;
    bool allsame=true;
    unordered_map<char,int> m;
    vector<int> charfreq(n,0);

    for(int i=0;i<len;i++){
        m[str[i]]++;
    }

    for(auto item:m){
        if(item.second>maxfreq)
            maxfreq=item.second;
    }

    for(auto item:m){
        charfreq[item.second]++;
    }

    for(int i=1;i<=maxfreq;i++){
        if(charfreq[i]>1)
            allsame=false;
    }
    if(allsame)
        return 0;
    //we maintain index value which can be allocated 1 from any other cell i.e. which has no occurence yet

    int idx=0;
    
    if(charfreq[1]>1){
        charfreq[0]=charfreq[1]-1;
        charfreq[1]=1;
        mindeletes+=charfreq[0]*1;
    }

    if(charfreq[1]==0)
        idx=1;

    for(int i=2;i<=maxfreq;i++){
        if(charfreq[i]>1){
            if(idx!=0){
                charfreq[i]--;
                mindeletes+=(i-idx);
                idx=0;

                if(charfreq[i]!=1){
                    charfreq[idx]=charfreq[i]-1;
                    mindeletes+=charfreq[idx]*i;
                    charfreq[i]=1;
                }
            }
            else{
                charfreq[0]=charfreq[i]-1;
                mindeletes+=charfreq[0]*i;
            }
        }
        else if(charfreq[i]==0){
                idx=i;
        }
    }
    return mindeletes;
}