#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int avoidTraps(vector<int>& obstacles, int n) ;

int main(){
    vector<int> obstacles={10,1,2,3,6,9};
    cout<<avoidTraps(obstacles,6);
    return 0;
}

int avoidTraps(vector<int>& obstacles, int n) {
    unordered_map<int,int> obscoord;
    bool found;
    int maxcoord=*max_element(obstacles.begin(),obstacles.end());

    for(int i=0;i<n;i++){
        obscoord[obstacles[i]]++;
    }

    int jumptry=2,minjump=1;

    do
    {
        found=true;
        for(int jump=jumptry;jump<=maxcoord;jump+=jumptry)
        {
            if(obscoord[jump]){
                found=false;
                break;
            }
        }
        if(found)
            minjump=jumptry;
        jumptry++;
    }while(not(found));
    
    return minjump;
}