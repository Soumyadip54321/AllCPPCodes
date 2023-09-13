#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool isReachable(int startX, int startY, int endX, int endY);

int main(){
    cout<<isReachable(1,1,1000,1);
    return 0;   
}
bool isReachable(int startX, int startY, int endX, int endY){
    if(startX==endX && startY==endY)
        return true;
    
    if(endX<startX || endY<startY)
        return false;
    
    if(isReachable(startX,startY,endX-endY,endY) || isReachable(startX,startY,endX,endY-endX))
        return true;
    return false;
}