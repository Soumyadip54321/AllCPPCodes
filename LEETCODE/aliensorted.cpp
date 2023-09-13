#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool isAlienSorted(vector<string>& words, string order);

unordered_map<char,int> hsh;

int main(){
    vector<string> words={"aa","a"};
    string order="abqwertyuioplkjhgfdszxcvnm";
    cout<<isAlienSorted(words,order)<<endl;
    return 0;
}
bool isAlienSorted(vector<string>& words, string order){
    /*idea:
    1. here we first put elements:index in unordered map
    2. Then we compare each words by their character index w.r.t char present in hsh
    */
   int start=0;
   vector<int> wordlength;
   for(int i=0;i<order.length();i++){
        hsh[order[i]]=i;
   }
    hsh[order[order.length()]]=-1;                  /*implies '\0' is hashed to '-1'*/
//    for(int i=0;i<order.length();i++){
//         cout<<order[i]<<":"<<hsh[order[i]]<<" ";
//    }
//    cout<<endl;
   /*for every unmatched character we compute the rank.
   1. if rank is higher than the word compared with and it's also present after we move forward
   2. else return false
   */
    for(int first=0;first<words.size();first++){
        for(int second=first+1;second<words.size();second++){
            for(int i=0;i<words[first].length();i++){
                if (hsh[words[first][i]]>hsh[words[second][i]])
                {
                    return false;
                }
                if(hsh[words[first][i]]<hsh[words[second][i]])
                    break;
            }
        }
    }
    return true;
}