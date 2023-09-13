#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int partitionString(string s);
vector<bool> visited(26,0);

int main(){
    string s="ssssss";
    cout<<partitionString(s);
    return 0;
}
int partitionString(string s){
    unordered_map<char,int> mpp;            //SC=O(n);
    int n=s.length(),ans=0;
    vector<bool> temp=visited;              //SC=O(1);

    for(int i=0;i<n;i++){   //TC=O(n);
        mpp[s[i]]++;
    }
    
    for(int end=0;end<n;end++){                     //TC=O(n);
        if(mpp[s[end]] and not(visited[s[end]-'a'])){
            mpp[s[end]]--;
            visited[s[end]-'a']=true;
        }
        else{
            visited=temp;
            ans++;

            mpp[s[end]]--;
            visited[s[end]-'a']=true;
        }
    }
    return ans+1;
    //TC=O(n), SC=O(n);
}