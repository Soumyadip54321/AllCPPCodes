#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

class Car {
public:
    int priceOfCar;
    int maintenanceCostPerMonth;
    int numberOfkilometerCarRunInOneLiter;
    int pricePerLiter;
    int numberOfKilometerCarRunInaMonth;
    Car(int priceOfCar, int maintenanceCostPerMonth, int numberOfkilometerCarRunInOneLiter,
        int pricePerLiter, int numberOfKilometerCarRunInaMonth) {
        
        this->priceOfCar = priceOfCar;
        this->maintenanceCostPerMonth = maintenanceCostPerMonth;
        this->numberOfkilometerCarRunInOneLiter = numberOfkilometerCarRunInOneLiter;
        this->numberOfKilometerCarRunInaMonth = numberOfKilometerCarRunInaMonth;
        this->pricePerLiter = pricePerLiter;
        
    }
};
int mostCostEfficientCar(Car petrolCar, Car dieselCar);

int main(){
    Car p1(207120,1500,20,40,120);
    Car d1(210000,1000,10,20,130);

    cout<<mostCostEfficientCar(p1,d1);
    return 0;
}
int mostCostEfficientCar(Car petrolCar, Car dieselCar){
    long long petrolcarcost,dieselcarcost;
    
    petrolcarcost=petrolCar.priceOfCar+(petrolCar.maintenanceCostPerMonth*6)+(((petrolCar.pricePerLiter)/petrolCar.numberOfkilometerCarRunInOneLiter)*petrolCar.numberOfKilometerCarRunInaMonth*6);
    dieselcarcost=dieselCar.priceOfCar+(dieselCar.maintenanceCostPerMonth*6)+(((dieselCar.pricePerLiter)/dieselCar.numberOfkilometerCarRunInOneLiter)*dieselCar.numberOfKilometerCarRunInaMonth*6);

    //cout<<petrolcarcost<<" "<<dieselcarcost<<endl;
    if(petrolcarcost<dieselcarcost)
        return 0;
    
    if(dieselcarcost<petrolcarcost)
        return 1;
    return -1;
}