#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int findKth(int N, int K);
bool isPossibleToSplit(int n, vector<int> &arr);

int main(){
    vector<int> arr={4, 3, 5, 6, 3};
    cout<<isPossibleToSplit(5,arr);
    //cout<<findKth(17,11);
    return 0;
}
int findKth(int N, int K){
    set<string> s;
    vector<int> lexorder;
    int num;

    while (N)       //TC=O(NLOG(N))
    {
        string str=to_string(N);
        s.insert(str);
        N--;
    }

    // for(auto n:s)
    //     cout<<n<<",";
    // cout<<endl;
    for(auto num:s){
        int no=stoi(num);
        lexorder.push_back(no);
    }
    return lexorder[K-1];
}
bool isPossibleToSplit(int n, vector<int> &arr){
    unordered_map<int,int> numcount;

    for(int i=0;i<n;i++)
        numcount[arr[i]]++;
    
    for(auto num:numcount){
        if(num.second<2)
            return false;
    }
    return true;
}