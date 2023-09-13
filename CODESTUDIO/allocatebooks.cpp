#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int findPages(vector<int>& arr, int n, int m);

int main(){
    vector<int> arr={25,26,28,49,24};
    cout<<findPages(arr,5,4);
    return 0;
}
int findPages(vector<int>& arr, int n, int m){
    //here we put m-1 partitions such that between each we have >= 1 books present
    int allocateminbooks=INT_MAX;

    /*set up partitions
    */
   
}