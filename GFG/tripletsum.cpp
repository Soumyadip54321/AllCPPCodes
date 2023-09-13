#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
bool findTriplets(int arr[], int n);


int main(){
    int arr[]={4,-16,43,4,7,-36,18};
    cout<<findTriplets(arr,7);
    return 0;
}
bool findTriplets(int arr[], int n){
    
    for(int i=0;i<n;i++){
        set<int> hash_set;
        for(int j=i+1;j<n;j++){
            int third=-1*(arr[i]+arr[j]);

            if(hash_set.find(third)!=hash_set.end())
                return 1;

            hash_set.insert(arr[j]);
        }
    }
    return 0;
}