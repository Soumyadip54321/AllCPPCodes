#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool lemonadeChange(int N, vector<int> &bills);

int main(){
    vector<int> bills={5,5,10,20,5,5,5,20};
    cout<<lemonadeChange(8,bills);
    return 0;
}
bool lemonadeChange(int N, vector<int> &bills){
    unordered_map<int,int> dollarct;

    /*
    now we observe that for $20 bills we need a 
    min:- 1:$5 and 1:$10 bills
    max:- 3:$5
    
    for a $10 bill we need
    1:$5 bill
    */

   /*
   so for every 
   1. $10 encountered we need that many number of $5's
   2. $20 encountered we require that many number of $10's and $5's to be present/3 $5's instead
   */
    for(auto val:bills){
        dollarct[val];
    }

    for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            dollarct[bills[i]]++;       //no change needed here
        }

        if(bills[i]==10){               //$5 change required
            if(dollarct[5]){
                dollarct[5]--;
            }
            else
                return false;
            dollarct[bills[i]]++;
        }

        if(bills[i]==20){                       //either $10 & $5 change needed or 3 $5's required
            if(dollarct[10] && dollarct[5]){
                dollarct[10]--;
                dollarct[5]--;
            }
            else if(dollarct[5]>=3){
                dollarct[5]-=3;
            }
            else
                return false;
            dollarct[20]++;
        }
    }
    return true;
}