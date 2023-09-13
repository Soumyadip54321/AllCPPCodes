#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
vector<bool> checkWordsInString(string &s, int n, vector<string> &wordList);
string specialString(string s, int n, int p);
bool checkforpalinformation(string);

int main(){
    string s="This is a large String",s3="abca";
    vector<string> wordList={"This", "this", "is", "age"};
    vector<bool> result;
    //result=checkWordsInString(s,4,wordList);
    cout<<specialString(s3,4,3);
    return 0;
}
vector<bool> checkWordsInString(string &s, int n, vector<string> &wordList){
    vector<bool> result;

    for(auto s1:wordList){
        if(s.find(s1)!=string::npos)
            result.push_back(true);
        else
            result.push_back(false);
    }
    return result;
}
string specialString(string s, int n, int p){
    /*
    idea:
    1. first check if all characters lie within the first p alphabels of Eng letters
    2. The we find the next lexicographically bigger string 
    3. We check to see if any palindrome of it exists
    */

   //first we find all lexicographically bigger strings of same length and same characters present

   string nextlexstr="",finalstr="";
   bool ispalin=true;
   char ch;

    for(int i=0;i<n;i++)
        finalstr+='a'+p-1;
    cout<<finalstr<<endl;

    while (not(s==finalstr))
    {
        int i=n;
        do
        {
            i--;
            ch=s[i];
            char newch=(((s[i]-'a')+1)%p)+'a';
            string str=s.substr(0,i)+newch+s.substr(i+1);
            s=str;
        }while(s[i]<=ch);

        if(not(checkforpalinformation(s)))
            return s;
    }
    return "NO";
}
bool checkforpalinformation(string str){
    unordered_map<char,int> m;
    int countoddchars=0;

    for(int i=0;i<str.length();i++){
        m[str[i]]++;
    }

    for(auto ch:m){
        if(ch.second%2!=0)
            countoddchars++;
    }

    if(countoddchars<=1)
        return true;
    return false;
}