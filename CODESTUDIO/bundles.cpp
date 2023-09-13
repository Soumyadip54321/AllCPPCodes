#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int groupsOfK(vector<string> &strList, int k);
int calculateprefix(string,string);
int maxDifference(int n, vector<int> &arr) ;

int main(){
    vector<string> strList={"hello","home","ninja","help"};
    vector<int> arr={0,6,4,8,9};
    cout<<maxDifference(5,arr)<<endl;
    //cout<<groupsOfK(strList,2);
    return 0;
}
int groupsOfK(vector<string> &strList, int k){
    unordered_map<int,pair<vector<string>,int>> m;
    int maxpre=0,grpct=1;

    m[grpct].first.push_back(strList[0]);

    for(int i=1;i<strList.size();i++){
        int grptobeputinto=-1;

        for(int j=grpct;j>=1;j--){
            if(calculateprefix(m[j].first[0],strList[i])>maxpre){
                grptobeputinto=j;
                maxpre=calculateprefix(m[j].first[0],strList[i]);
            }
        }
        if(grptobeputinto==-1){
            if(grpct<strList.size()/k){
                grpct++;
                m[grpct].first.push_back(strList[i]);
            }
            else{
                m[grpct].first.push_back(strList[i]);
            }
        }
        else{
            m[grptobeputinto].first.push_back(strList[i]);
        }
        maxpre=0;
    }

    for(int i=1;i<=strList.size()/k;i++){
        for(auto s:m[i].first)
            cout<<s<<",";
        cout<<endl;
    }
    return 0;
}
int calculateprefix(string s1,string s2){
    int len=min(s1.length(),s2.length());
    int numpre=0;

    for(int i=0;i<len;i++){
        if(s1[i]==s2[i])
            numpre++;
        else
            break;
    }
    return numpre;
}
int maxDifference(int n, vector<int> &arr) 
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    int maxdiff=-1;

    maxdiff=max(arr[1]-arr[0],arr[n-1]-arr[n-2]);

    for(int i=1;i<n-1;i++){
        maxdiff=max(maxdiff,max(arr[i]-arr[i-1],arr[i+1]-arr[i]));
    }
    return maxdiff;
}