#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int sumOfSquares(vector<int>& nums);


int main(){
    vector<int>& nums={2,7,1,19,18,3};
    cout<<sumOfSquares(nums);
    return 0;
}
int sumOfSquares(vector<int>& nums){
    //1-indexed
    int size=nums.size(),total=0;

    for(int i=0;i<size;i++){
        if(size%(i+1)==0){
            total+=nums[i]*nums[i];
        }
    }
    return total;
}