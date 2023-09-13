#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string finalString(string s);

int main(){
    string s="poiinter";
    cout<<finalString(s);
    return 0;
}
string finalString(string s){
    string ans;
    int n=s.length();

    for(int i=0;i<n;i++){
        if(s[i]=='i'){
            reverse(ans.begin(),ans.end());
        }
        else
            ans+=s[i];
    }
    return ans;
}