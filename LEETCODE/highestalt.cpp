#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int largestAltitude(vector<int>& gain);


int main(){
    vector<int> gain={-4,-3,-2,-1,4,3,2};
    cout<<largestAltitude(gain)<<endl;
    return 0;
}
int largestAltitude(vector<int>& gain){
    for(int i=1;i<gain.size();i++){
        gain[i]+=gain[i-1];
    }
    return max(0,*max_element(gain.begin(),gain.end()));
}