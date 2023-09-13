#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
string FirstNonRepeating(string A);

int main(){
    string str="tcpmxaixsswjelbswxytyhbwjinuhxhvpwaybmdhndafszoghpyzdahiqsgluufqcekjk";
    cout<<FirstNonRepeating(str)<<endl;
    return 0;
}
string FirstNonRepeating(string A){
    /*
    idea: 2 ptr method
    1. at first we mark the starting character with ptr-f
    2. Another ptr checks whether the new character is same or diff than the one marked by f
    3. If found same we append a '#' in the output string
    4. else we change the ptr-f to now point at the new character and put that in string
    */

   int fptr=0,sptr=1,n=A.length(),idx=0;
   string outputstr="";
   map<int,pair<int,int[2]>> m;         //form:(idxofchar,(freq,(firstelidx,secelidx)))
   vector<char> ch;

    for(int i=0;i<n;i++){
        if(m[i].first==0){
            m[i].first++;
            m[i].second[0]=i;
            m[i].second[1]=INT_MAX;
        }

        if(m[i].first==1){
            m[i].first++;
            m[i].second[1]=i;
        }
    }

    //we create a vector with only those characters such that for every 2 consecutive ones the later appears onece
    //in between that of 2 occurances of former and second time it occurs is after the seconf occurance of the first character
    // for(auto val:m){
    //     if(ch.empty()){
    //         ch.push_back(val.first);
    //         idx++;
    //     }
    //     else{
    //         if(val.second.second[0]>m[ch[idx-1]].second[0] && val.second.second[1]>m[ch[idx-1]].second[1]){
    //             ch.push_back(val.first);
    //             idx++;
    //         }
    //     }
    // }

    // for(auto items:ch)
    //     cout<<items<<",";
    // cout<<endl;

    for(auto item:m){
        cout<<A[item.first]<<"->"<<"("<<item.second.first<<"("<<item.second.second[0]<<","<<item.second.second[1]<<"))"<<endl;
    }

    // int maplen=m.size();
    // outputstr+=A[0];
    // if(sptr==n)
    //     return outputstr;

    // while (true)
    // {
        
    // }
    
   return outputstr;
}