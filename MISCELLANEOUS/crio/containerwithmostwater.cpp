#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int maxArea(vector<int>& height);

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height)<<endl;
    return 0;
}
int maxArea(vector<int>& height){
    /*2 pointer approach*/
    int st=0,end=height.size()-1,maxarea=-1;
    while (st<end)
    {
        if(height[st]<height[end]){
            maxarea=max(maxarea,(end-st)*height[st]);
            st++;
        }
        else{
            maxarea=max(maxarea,(end-st)*height[end]);
            end--;
        }
    }
    return maxarea;
}