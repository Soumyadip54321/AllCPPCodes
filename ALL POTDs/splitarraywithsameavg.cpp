#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

bool splitListWithSameAverage(vector<int>& strengths);
bool checksameavg(vector<int>,double,double,int);

int main(){
    vector<int> strengths={1,7,15,29,11,9};
    cout<<splitListWithSameAverage(strengths);
    return 0;
}
bool splitListWithSameAverage(vector<int>& strengths){
    int n=strengths.size();
    double ravg=0.0,lavg=0.0;

    for(auto val:strengths)
        ravg+=val;
    ravg=(ravg/n);

    return checksameavg(strengths,lavg,ravg,0);
}
bool checksameavg(vector<int> s,double Bavg,double Aavg,int idx){
    if(Bavg==Aavg)
        return true;

    if(idx>=s.size())
        return false;
    
    if(Bavg<Aavg){
        double lsum=s[idx]
    }
}