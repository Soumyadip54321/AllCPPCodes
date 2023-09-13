#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int hotelBookings(vector<string> queries);


int main(){
    vector<string> queries={"+1A", "+3E", "-1A", "+4F","+1A","+3E"};
    cout<<hotelBookings(queries)<<endl;
    return 0;   
}
int hotelBookings(vector<string> queries){
    int ctcoins=0;
    for(auto str:queries){
        if(str[0]=='+')
            ctcoins++;
    }
    return ctcoins;
}