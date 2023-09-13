#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int LCS(string A, string B, string C, int n, int m, int k);

int main(){
    string A="legcefslwjytjaf" ,B="kzmjaftmxmarpikdwkhf" ,C="legcefslwjytjaf";
    cout<<LCS(A,B,C,15,20,15);
    return 0;
}
int LCS(string A, string B, string C, int n, int m, int k){
    string LCSof3strings="";
    set<string> commonsub12;
    int i=0,curr=i;

    if(n>m)
        swap(A,B);

    while (true)
    {
        string str="";
        for(int j=0;j<B.length();j++){
            if(B[j]==A[i]){
                str+=B[j];
                i++;
            }
        }
        if(str.length())
            commonsub12.insert(str);

        if(i>=n)
            break;
        i=curr+1;
        curr=i;
    }
    

    for(auto str:commonsub12)
        cout<<str<<endl;

    for(auto sub:commonsub12){
        int i=0,j=0;
        string s1="";

        while(i<k && j<sub.length()){
            if(C[i]==sub[j]){
                s1+=C[i];
                j++;
            }
            i++;
        }
        //cout<<s1<<endl;
        if(s1.length()>LCSof3strings.length()){
            LCSof3strings=s1;
        }
    }
    cout<<LCSof3strings<<endl;
    return LCSof3strings.length();
}