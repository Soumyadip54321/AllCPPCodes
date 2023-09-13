#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector< int > corpFlightBookings(vector< vector < int > > &bookings, int n);

int main(){
    vector< vector < int > > bookings={{1,2,3},{2,3,2},{1,3,1},{3,4,2}};
    vector<int> flightseatsbooked;
    flightseatsbooked=corpFlightBookings(bookings,4);
    return 0;
}
vector< int > corpFlightBookings(vector< vector < int > > &bookings, int n){
    vector<int> seatsbooked(n,0);
    int numbookings=bookings.size();

    for(int r=0;r<numbookings;r++){                                     //TC=O(M*N);
        for(int seats=bookings[r][0]-1;seats<bookings[r][1];seats++)
            seatsbooked[seats]+=bookings[r][2];
    }
    return seatsbooked;
}