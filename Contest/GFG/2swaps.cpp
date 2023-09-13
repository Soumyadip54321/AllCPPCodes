#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

bool checkSorted(int N, vector<int> A);
bool issorted(vector<int>);

int main(){
    vector<int> A={1,2};
    cout<<checkSorted(2,A);
    return 0;
}
bool checkSorted(int N, vector<int> A){
    /*
    idea:
    1. array has 1st N natural numbers hence it has numbers in seq from 1 to N+1
    2. in sorted case every number must be positioned at index num[i]-1
    */
    int i=0,numswaps=0;
    int num=1;

    if(N==1)
        return false;

    if(issorted(A))
        return true;

    while (numswaps<3 and i<N)
    {
        if(A[i]!=num){
            swap(A[A[i]-1],A[i]);
            numswaps++;
        }
        else{
            num++;
            i++;
        }
    }
    if(numswaps==2)
        return true;
    return false;
}
bool issorted(vector<int> nums){
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]<nums[i])
            return false;
    }
    return true;
}   