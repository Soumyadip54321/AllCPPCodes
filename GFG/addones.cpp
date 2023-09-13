#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void update(int a[], int n, int updates[], int k);


int main(){
    int a[]={0,0},updates[]={1,1,1};
    update(a,2,updates,3);
    return 0;
}
void update(int a[], int n, int updates[], int k){
    for(int i=0;i<k;i++){
        a[updates[i]-1]++;
    }
    for(int i=1;i<n;i++)
        a[i]+=a[i-1];

}