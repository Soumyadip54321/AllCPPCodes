#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int maxVowels(string s, int k);
void update_vowel_count(string);

const int N=1e5+10;
int hsh[N];


int main(){
    string s="take u forward";
    int k=3;
    cout<<maxVowels(s,k)<<endl;
    return 0;
}
int maxVowels(string s, int k){
    int maxvowelct=0;
    update_vowel_count(s);
    // for(int i=0;i<=s.length();i++)
    //     cout<<hsh[i]<<" ";
    // cout<<endl;

    //compute max vowels in the substring
    for(int i=0;i<=s.length()-k;i++){
        maxvowelct=max(maxvowelct,hsh[i+k]-hsh[i]);
    }
    return maxvowelct;
}
void update_vowel_count(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            hsh[i+1]++;
        }
    }
    //we perform prefix sum here
    for(int i=1;i<=s.length();i++){
        hsh[i]+=hsh[i-1];
    }
}   