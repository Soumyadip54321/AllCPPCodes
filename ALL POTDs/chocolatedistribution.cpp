#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m);

int main(){
    vector<long long> a={7,3,2,4,9,12,56};
    cout<<findMinDiff(a,7,3);
    return 0;
}
long long findMinDiff(vector<long long> a, long long n, long long m){
    /*
    idea:
    1.  first we sort elements
    2.  with length=m we select the first & (m-1)th entry from start for this'd give the max and min chocolates anyone would have recieved
    3.  every time we run through the array we update our ans that stores the min diff b/w max and min chocolates until we reach the end
    */
   sort(a.begin(),a.end());                 //TC=O(nlg(n));
   int i=0,j=i+m-1;
   long long mindiff=__LONG_LONG_MAX__;

   while (j<n)
   {
        mindiff=min(mindiff,a[j]-a[i]);
        i++;
        j++;
   }
   return mindiff;
}