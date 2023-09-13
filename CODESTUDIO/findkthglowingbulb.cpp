#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
long long findKthGlowingBulb(vector<int> &labels, long long k);


int main(){
    vector<int> labels={2,3};
    cout<<findKthGlowingBulb(labels,6);
    return 0;
}
long long findKthGlowingBulb(vector<int> &labels, long long k){
    //we find the largest label from labels and include bulb labels uptil k*max(labels)
    // int maxlabel=*max_element(labels.begin(),labels.end());
   set<long long> s;       //set of form (bulbON of label multiplier,label)
    long long kthbulb;

   for(auto val:labels){
       s.insert(val);
   }

   while (k)
   {
        
        kthbulb=
        p.first+=p.second;
        s.push(p);
        k--;
   }
   return kthbulb;
}