#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int subarraysWithSumK(vector < int > a, int b);

int main(){
    vector < int > a={4,2,2,6,4};
    cout<<subarraysWithSumK(a,6);
    return 0;
}
int subarraysWithSumK(vector < int > a, int b){
    map<int,int> m;           //hashmap stores elements in the form (frontXOR's,count);
    int xorofitems=0,ans=0;

    m[xorofitems]++;

    for(int i=0;i<a.size();i++){
        xorofitems^=a[i];
        int x=xorofitems^b;
        ans+=m[x];      //return number of times x appears in map if it does else returns 0.
        m[xorofitems]++;
    }
    return ans;
}