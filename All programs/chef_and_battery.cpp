#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int chef_and_battery(int);


int main(){
    int testcases;
    cin>>testcases;

    while(testcases!=0){                //51,50,23,0
                                            //per minute on charging lvl increases by 2% and when not reduces by 3%.
        int bat_level;
        cin>>bat_level;
        cout<<chef_and_battery(bat_level)<<endl;
        testcases--;
    }
    return 0;
}
int chef_and_battery(int battery_percent){
    if(battery_percent==50)
        return 0;
    
    int min_time=0;
    
    while(battery_percent!=50){
        if(battery_percent<50){
            battery_percent+=2;
            min_time++;
        }
        else if(battery_percent>50){
            battery_percent-=3;
            min_time++;
        }
    }
    return min_time;
}