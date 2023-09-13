#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int laststoneweight(vector<int>);
bool powerofnum(int,int);
int bulbSwitch(int n);
int bulbSwitchoptimized(int n);
int togglebulb(int[],int,int);

int main(){
    vector<int> stones={2,7,4,1,8,1};
    cout<<laststoneweight(stones)<<endl;
    cout<<powerofnum(282475248,7)<<endl;
    cout<<bulbSwitch(3)<<endl;
    cout<<bulbSwitchoptimized(3)<<endl;
    return 0;
}
int laststoneweight(vector<int> stonewts){

    if(stonewts.size()==1)
        return stonewts[0];
    if(stonewts.size()==0)
        return 0;

    sort(stonewts.begin(),stonewts.end());

    if(stonewts[stonewts.size()-1]==stonewts[stonewts.size()-2])
        stonewts.resize(stonewts.size()-2);
    
    else if (stonewts[stonewts.size()-2]<=stonewts[stonewts.size()-1]){
        stonewts[stonewts.size()-2]=stonewts[stonewts.size()-1]-stonewts[stonewts.size()-2];
        stonewts.resize(stonewts.size()-1);
    }
    return laststoneweight(stonewts);
}
bool powerofnum(int num,int div){
    if(num==0 || num==div)
        return true;
    else if(num==1)
        return false;

    if(num%div==0)
        return powerofnum(num/div,div);
    return false;
    
}
int bulbSwitch(int n){
    int *bulbstatus=new int[n],numbulbon=0;
    if(n==0)
        return 0;
    for(int i=0;i<n;i++)
        bulbstatus[i]=1;

    return togglebulb(bulbstatus,n,2);
}
int togglebulb(int bulbstatus[],int round,int roundnum){
    if (roundnum==round+1){
        for(int i=1;i<round;i++)
            bulbstatus[0]+=bulbstatus[i];
        return bulbstatus[0];
    }
        
    for(int i=roundnum-1;i<round;i+=roundnum){
        if(bulbstatus[i]==1)
            bulbstatus[i]=0;
        else{
            bulbstatus[i]=1;
        }
    }
    return togglebulb(bulbstatus,round,roundnum+1);
}
int bulbSwitchoptimized(int n){
    return floor(pow(n,0.5));
}
