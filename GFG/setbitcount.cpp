#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int setBits(int N);

int main(){
    cout<<setBits(8);
    return 0;
}
int setBits(int N){
    int setbitct=0;

    while (N)
    {
        if((N & 1)==1)
            setbitct++;
        N=N>>1;
    }
    return setbitct;
}