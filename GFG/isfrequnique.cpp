#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool isFrequencyUnique(int n, int arr[]);
vector<int> searchWords(string booklet, vector<string> &diary);

int main(){
    int arr[]={2, 2, 5, 10, 1, 2, 10, 5, 10, 2};
    string booklet="ahishers";
    vector<string> diary={"he","she","his","hers"};
    vector<int> stindices;

    //cout<<isFrequencyUnique(10,arr);
    stindices=searchWords(booklet,diary);
    return 0;
}
bool isFrequencyUnique(int n, int arr[]){
    unordered_map<int,int> freq;
    unordered_map<int,int> freqct;

    for(int i=0;i<n;i++)
        freq[arr[i]]++;
    
    for(auto val:freq){
        freqct[val.second]++;
    }

    for(auto f:freqct){
        if(f.second>1)
            return false;
    }
    return true;
}
vector<int> searchWords(string booklet, vector<string> &diary){
    int size=booklet.length();
    vector<int> stindices;

    for(int i=0;i<diary.size();i++){
        int s=0;
        while (s<=size-diary[i].length())
        {
            if(booklet[s]==diary[i][0]){
                string str=booklet.substr(s,diary[i].length());

                if(str==diary[i]){
                    stindices.push_back(s);
                    break;
                }
            }
            s++;
        }
    }

    sort(stindices.begin(),stindices.end());

    // for(auto indices:stindices)
    //     cout<<indices<<",";
    // cout<<endl;

    return stindices;
}