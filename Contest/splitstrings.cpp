#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> splitWordsBySeparator(vector<string>& words, char separator);

int main(){
    vector<string> ans;
    vector<string> words={"|||"};
    char sep='|';

    ans=splitWordsBySeparator(words,sep);
    return 0;
}
vector<string> splitWordsBySeparator(vector<string>& words, char separator){
    vector<string> ans;
    int n=words.size();
    
    for(auto s:words){
        string str="";
        for(int i=0;i<=s.length();i++){

            if((s[i]==separator || i==s.length())){
                if(not(str.empty())){
                    ans.push_back(str);
                    str="";
                }
            }
            else
                str+=s[i];
        }
    }

    // for(auto s:ans)
    //     cout<<s<<" ";
    // cout<<endl;

    return ans;
}