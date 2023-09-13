#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int find(int n, vector<int> &position, vector<int> &speed, int d);


int main(){
    vector<int> position={1, 2, 3, 5, 6, 8, 11, 12, 14, 15, 16, 17, 18, 20, 21, 22, 25, 26, 28, 29, 32, 34, 35, 36, 39, 40, 41},speed={66, 95, 96, 95, 65, 59, 77, 80, 24, 80, 14, 1, 68, 12, 28, 86, 75, 54, 43, 95, 92, 11, 41, 35, 74, 99, 19};
    cout<<find(27,position,speed,45);
    return 0;
}
int find(int n, vector<int> &position, vector<int> &speed, int d){
    vector<int> timetoD;
    unordered_map<int,int> uniquetimes;
    int uarrivalt=0;

    for(auto pos:position){
        timetoD.push_back((d-pos));
    }

    for(int i=0;i<n;i++){
        timetoD[i]=round(timetoD[i]/speed[i]);
        uniquetimes[timetoD[i]]++;
    }
    for(auto t:timetoD)
        cout<<t<<",";
    cout<<endl;

    for(auto t:uniquetimes){
        if(t.second==1)
            uarrivalt++;
    }
    return uarrivalt;
}