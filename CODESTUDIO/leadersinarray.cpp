#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> findLeaders(vector<int> &elements, int n);

int main(){
    vector<int> elements={11,10,9,8},leaders;
    leaders=findLeaders(elements,4);
    return 0;
}
vector<int> findLeaders(vector<int> &elements, int n){
    vector<int> allleaders;
    int leader=elements[n-1],i=n-2;

    allleaders.push_back(elements[n-1]);
    while (i>=0)
    {
        if(elements[i]>leader){
            allleaders.push_back(elements[i]);
            leader=elements[i];
        }
        i--;
    }

    reverse(allleaders.begin(),allleaders.end());

    // for(auto val:allleaders)
    //     cout<<val<<",";
    // cout<<endl;

    return allleaders;
}