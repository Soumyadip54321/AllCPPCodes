#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

long long MaxXP(int n, int k, int initial_exp, vector<int>& exp_req, vector<int>& exp_gain);
void computemaxxpwithatmostkquests(vector<pair<int,int>>,int,int,int);
int maxXPgained=-1;

int main(){
    vector<int> exp_req={3,2,4,1,2},exp_gain={5,3,6,2,4};
    cout<<MaxXP(5,3,10,exp_req,exp_gain);
    return 0;
}
long long MaxXP(int n, int k, int initial_exp, vector<int>& exp_req, vector<int>& exp_gain){
    vector<pair<int,int>> v;
    unordered_map<int,bool> mpp;

    for(int i=0;i<n;i++)
        v.push_back({exp_req[i],exp_gain[i]});      //form:(exp_req,exp_gained);
    
    sort(v.begin(),v.end());

    computemaxxpwithatmostkquests(v,0,k,initial_exp);
    return maxXPgained;
}
void computemaxxpwithatmostkquests(vector<pair<int,int>> v,int idx,int possiblequests,int init_XP){
    if(idx==v.size() and possiblequests){
        maxXPgained=max(maxXPgained,init_XP);
        return;
    }

    if(possiblequests==0 or init_XP<v[idx].first){
        maxXPgained=max(maxXPgained,init_XP);
        return;
    }

    computemaxxpwithatmostkquests(v,idx+1,possiblequests-1,init_XP+v[idx].second);
    computemaxxpwithatmostkquests(v,idx+1,possiblequests,init_XP);
}