#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
const int n=1e6+10;

class UndergroundSystem {
    int checkedinout[n];
    unordered_map<string,int[n]> m;
public:
    UndergroundSystem() {
        for(int i=0;i<n;i++)
            checkedinout[i]=0;
    }
    void checkIn(int id, string stationName, int t) {
        checkedinout[id]++;
        m[stationName][id]=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        checkedinout[id]++;
        m[stationName][id]=t;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double cumintime=0,cumouttime=0,ct=0;

        for(int i=0;i<n;i++){
            if(checkedinout[i]==2 && m[startStation][i]>0 && m[endStation][i]>0){
                cumintime+=m[startStation][i];
                cumouttime+=m[endStation][i];
                ct++;
            }
        }
        return abs(cumintime-cumouttime)/ct;
    }
};

int main(){
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(10, "Leyton", 3);
    undergroundSystem.checkOut(10, "Paradise", 8); // Customer 10 "Leyton" -> "Paradise" in 8-3 = 5
    cout<<undergroundSystem.getAverageTime("Leyton", "Paradise")<<endl; // return 5.00000, (5) / 1 = 5
    undergroundSystem.checkIn(5, "Leyton", 10);
    undergroundSystem.checkOut(5, "Paradise", 16); // Customer 5 "Leyton" -> "Paradise" in 16-10 = 6
    cout<<undergroundSystem.getAverageTime("Leyton", "Paradise")<<endl; // return 5.50000, (5 + 6) / 2 = 5.5
    undergroundSystem.checkIn(2, "Leyton", 21);
    undergroundSystem.checkOut(2, "Paradise", 30); // Customer 2 "Leyton" -> "Paradise" in 30-21 = 9
    cout<<undergroundSystem.getAverageTime("Leyton", "Paradise")<<endl; // return 6.66667, (5 + 6 + 9) / 3 = 6.66667c    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
    return 0;
}