#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

string sortVowels(string s);

int main(){
    string str="lEetcOde";
    cout<<sortVowels(str)<<endl;
    return 0;
}
string sortVowels(string s){
    string res="",vowels="aAeEiIoOuU";
    unordered_map<char,bool> m;
    priority_queue<int,vector<int>,greater<int>> pq;        //min heap
    vector<pair<int,int>> vowelval;

    int n=s.length();

    for(int i=0;i<vowels.length();i++){
        m[vowels[i]]=true;
    }

    for(int i=0;i<n;i++){
        if(m[s[i]]){
            pq.push(s[i]+0);
        }
    }

    for(int i=0;i<n;i++){
        if(m[s[i]]){    
            res+=pq.top();                          //IMPLICIT CONVERSION
            //cout<<pq.top()+'0'<<endl;
            pq.pop();
        }
        else
            res+=s[i];
    }
    return res;
}