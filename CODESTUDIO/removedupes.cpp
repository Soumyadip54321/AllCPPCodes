#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int removeDuplicates(vector<int> &arr, int n);
int kDistinctChars(int k, string &str);


int main(){
    vector<int> arr={1,1,2,2,3,4,5,5,6};
    string str="acgttredcvvbhuiopqwerttedssdrew";
    //cout<<removeDuplicates(arr,9)<<endl;
    cout<<kDistinctChars(5,str)<<endl;
    return 0;
}
int removeDuplicates(vector<int> &arr, int n){
    /*
    idea:
    1. we iterate through the list
    2. since it's sorted for every second occurance of an entry we remove it from the list
    */
   int lengthofunique=n;
   for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])
            lengthofunique--;
   }
   return lengthofunique;
}
int kDistinctChars(int k, string &str){
    /*
    idea:
    1. we iterate throught he characters until number of unique char > K
    2. here we insert the string in list and increase the start ptr by 1
    3. we repeat the step until we hit the end of string
    */
   unordered_map<char,int> m;
   int maxlen=-1,j=0;

   for(auto ch:str)
    m[ch];

   for(int i=0;i<str.length();i++){
        int uct=0;
        int sublen=0;
        int prev=i;
        j=i+1;
        uct++;
        sublen++;
        m[str[i]]=1;                        /*indicates visited*/
        while (uct<=k && j<str.length())
        {
            if(m[str[j]]==0){
                uct++;
                m[str[j]]=1;
            }

            if(uct>k)
                break;

            sublen++;
            prev=j;
            j++;
        }

        for(auto ch:str)
            m[ch]=0;                    /*restoring unvisited state*/
        //cout<<uct<<" "<<j<<endl;
        maxlen=max(maxlen,sublen);
        if(j==str.length()-1)
            break;
   }
   return maxlen;
}
