#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int findDoubleStrings(string& str);

int main(){
    string str="babcdacdacaabcaabccabcbcccbccbcdcdbda";
    cout<<findDoubleStrings(str);
    return 0;
}
int findDoubleStrings(string& str){
    //we use 4 ptr method
    int f=0,p1=0,distictdoublect=0;
    set<string> s;
    string temp1;

    do
    {
        if(p1==f){
            temp1="";
            temp1+=str[f];
            p1++;
        }

        if(str[p1]!=str[f]){
            temp1+=str[p1];
            p1++;

            if(p1>=str.length()){
                f++;
                p1=f;
            }

        }
        else{
            if(temp1.length()>str.length()-p1){
                f++;
                p1=f;
                continue;
            }

            int n=temp1.length();
            string news=str.substr(p1,n);
            
            if(news==temp1){
                s.insert(news);
                temp1+=news[0];
                p1++;
            }
            else{
                f++;
                p1=f;
            }
        }
    }while (f<str.length());

    for(auto item:s)
        cout<<item<<",";

    return s.size();
}