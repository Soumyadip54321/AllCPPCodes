#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
long long int countStrings(string s);

int main(){
    string str="abaaabb";
    cout<<countStrings(str);
    return 0;
}
long long int countStrings(string s){
    int n=s.length();
        long long ans=0;
        
        // ans=fact(n);
        sort(s.begin(),s.end());
        long long same=1;
        char prev=s[0];
        

        for(int i=1;i<n;i++){
            if(s[i]==prev)
                same++;
            else{
                ans+=same*(n-i);
                prev=s[i];
                same=1;
            }
        }
        return ans+1;

        /*TC=O(nlg(n))*/
}