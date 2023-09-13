#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool isKthBitSet(int n, int k);

int main(){
    cout<<isKthBitSet(128,7);
    return 0;
}
bool isKthBitSet(int n, int k){
    if(((n>>(k-1)) & 1)==1)
        return true;
    return false;
}