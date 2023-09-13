#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int digitprod(int);

int main(){
    cout<<digitprod(36);
    return 0;
}
int digitprod(int num){

    if(num/10==0){
        return num;
    }
    //we find a value s.t when num/value we get a digit result

    for(int i=1;i<10;i++){
        
    }
}