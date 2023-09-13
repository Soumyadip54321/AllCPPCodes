#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool canMakeArithmeticProgression(vector<int>& arr);


int main(){
    vector<int> arr={1,2,4};
    cout<<canMakeArithmeticProgression(arr)<<endl;
    return 0;
}
bool canMakeArithmeticProgression(vector<int>& arr){
    /*naive approach
    1. sort array
    2. check if common difference is same b/w corresponding terms
    */
   sort(arr.begin(),arr.end());
   int cd=arr[1]-arr[0];

   for(int i=2;i<arr.size();i++){
        if(arr[i]-arr[i-1]!=cd)
            return false;
   }
   return true;
}