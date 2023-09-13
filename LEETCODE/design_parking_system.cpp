#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class ParkingSystem {
    int spaces[4];
public:
    ParkingSystem(int big, int medium, int small) {
        spaces[1]=big;
        spaces[2]=medium;
        spaces[3]=small;
    }
    
    bool addCar(int carType) {
        if(spaces[carType]>0){
            spaces[carType]--;
            return true;
        }
        return false;
    }
};


int main(){
    ParkingSystem park(1,1,0);
    cout<<park.addCar(1)<<endl;
    cout<<park.addCar(2)<<endl;
    cout<<park.addCar(3)<<endl;
    cout<<park.addCar(1)<<endl;
    return 0;
}