#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b);

int main(){
    vector<long long> a={1, 8, 8},b={2, 3, 4, 5};
    mergeTwoSortedArraysWithoutExtraSpace(a,b);
    return 0;
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
    int asize=a.size(),bsize=b.size(),p1,p2=0;       //SC=O(1)
    p1=asize-1;

    while (p1>=0 && p2<bsize)                        //TC=O(min(asize,bsize));
    {
            if(a[p1]>b[p2])
                swap(a[p1],b[p2]);
            
            p1--;
            p2++;
    }

    //now we simply sort the arrays
    sort(a.begin(),a.end());                     //TC=O(asizelog(asize))
    sort(b.begin(),b.end());
}