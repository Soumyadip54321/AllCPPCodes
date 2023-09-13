#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> allterms;
vector < int > termsOfAP(int x);
void computeterms();

int main(){
    vector<int> APterms;
    APterms=termsOfAP(5);
    return 0;
}
vector<int> termsOfAP(int x){

    if(allterms.empty())
        computeterms();
    
    vector<int> firstxterms(allterms.begin(),allterms.begin()+x);

    // for(auto val:firstxterms)
    //     cout<<val<<",";
    // cout<<endl;

    return firstxterms;
}
void computeterms(){
    int i;
    for(i=1;i<=1e5;i++){
        if((3*i+2)%4!=0)
            allterms.push_back(3*i+2);
    }
}