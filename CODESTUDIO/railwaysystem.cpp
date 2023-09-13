#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

const int n=1010;

class railwaySystem{
    unordered_map<string,int[n]> arrival;
    unordered_map<string,int[n]> departure;
public:
    railwaySystem(){
        // Declare the data structures here.       
    }

    void checkIn(int passID, string station, int time){
        // Write your code here.

        for(int i=0;i<n;i++)
            arrival[station][i]=0;
        arrival[station][passID]=time;
    }

    void checkOut(int passID, string station, int time){
        // Write your code here.
        for(int i=0;i<n;i++)
            departure[station][i]=0;
        departure[station][passID]=time;
    }

    double getAverage(string source, string dest){
        // Write your code here.
        int numcustomer=0;
        int i=0,sum=0;
        while (i<n)
        {
            if(arrival[source][i]!=0 && departure[dest][i]!=0){
                numcustomer++;
                sum+=(departure[dest][i]-arrival[source][i]);
            }
            i++;
        }
        return (sum*1.0)/(numcustomer*1.0);
    }
};

/*
idea:
1. we create a map with all station names as key and corresponding value as an array with indices as
    passenger ID
*/


int main(){
    railwaySystem r;
    r.checkIn(734,"Agra",59);
    r.checkOut(734,"Ahemdabad",69);
    //cout<<r.getAverage("Kota","Chandigarh")<<endl;
    r.checkIn(831,"Kota",53);
    r.checkOut(831,"Delhi",89);
    //r.checkIn(79,"Agra",37);
    cout<<r.getAverage("Kota","Delhi")<<endl;
    // r.checkOut(79,"Noida",54);
    // r.checkIn(373,"Lucknow",65);

    return 0;
}