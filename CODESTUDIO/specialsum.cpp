#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int specialSum(vector<int>& arr, int n);
int getMinimumAnagramDifference(string &str1, string &str2);
int repetition(string &s1, string &s2, int n1, int n2);

int main(){
    vector<int> arr={4,2,1,1};
    string str="ninja",str2="ninja",s1="sicmundascreatersest",s2="createset";
    //cout<<getMinimumAnagramDifference(str,str2);
    cout<<repetition(s1,s2,3,3);
    //cout<<specialSum(arr,4);
    return 0;
}
int specialSum(vector<int>& arr, int n){
    string str;
    long long num=0;

    for(auto val:arr)
        num+=val;
    str=to_string(num);
    

    while (str.length()>1)
    {
        num=0;
        for(int i=0;i<str.length();i++){
            num+=str[i]-'0';
        }
        str=to_string(num);
    }
    return str[0]-'0';
}
int getMinimumAnagramDifference(string &str1, string &str2){
    unordered_map<char,int> m;
    int nummoves=0;

    if(str1==str2)
        return 0;
    
    for(int i=0;i<str1.length();i++){
        m[str1[i]]++;
    }

    for(int i=0;i<str2.length();i++){
        if(m[str2[i]]==0)
            nummoves++;
        else
            m[str2[i]]--;
    }
    return nummoves;
}
int repetition(string &s1, string &s2, int n1, int n2){
    unordered_map<char,int> c;
    string news1="",temp="";
    int reps=0;

    for(int i=0;i<s2.length();i++)
        c[s2[i]]++;
    
    for(auto ch:s1){
        if(c[ch]){
            news1+=ch;
        }
    }

    if(news1==s2){
        if(n1>=n2)
            return n1/n2;
        return 0;
    }
        
    for(int i=0;i<n1;i++){
        temp+=news1;
    }
    news1=temp;
    cout<<news1<<endl;
    //we use 2 ptr here
    int start=0,end=start+s2.length();
    while (end<news1.length())
    {
        string n="";
        for(int i=start;i<end;i++)
            n+=news1[i];
        if(n==s2)
            reps++;
        start=end;
        end=start+s2.length();
    }
    cout<<reps<<endl;

    if(reps<n2)
        return reps;
    return reps/n2;
}