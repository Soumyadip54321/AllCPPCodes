#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

double soupServings(int n);
void prob(int,int,double);
vector<vector<int>> options={{100,0},{75,25},{50,50},{25,75}};
double total=0.0;

int main(){
    cout<<soupServings(1);
    return 0;
}
double soupServings(int n){
    double ans=1.0;
    prob(n,n,ans);
    return total;
}
void prob(int na,int nb,double ans){
    //BRUTE FORCE RECURSION
   if(na==0 and nb==0){
        total+=ans*0.5;
        return;
   }
   if(na==0 and nb>0){
        total+=ans;
        return;
   }

   if(na>0 and nb<=0)
        return;
    
   for(int i=0;i<4;i++){
        if(na<options[i][0] and nb>=options[i][1]){
            prob(0,nb-options[i][1],ans*0.25);
        }
        if(na>=options[i][0] and nb<options[i][1]){
            prob(na-options[i][0],0,ans*0.25);
        }
        if(na<options[i][0] and nb<options[i][1]){
            prob(0,0,ans*0.25);
        }
        if(na>=options[i][0] and nb>=options[i][1])
            prob(na-options[i][0],nb-options[i][1],ans*0.25);
   }
}