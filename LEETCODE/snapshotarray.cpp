#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
/*
idea:
1. we consider a matrix of size 1e5 by 1e5
2. the row's are represented by indexes while cols by snap_id's
*/
const int n=1e5+10;
int numbers[n];

class SnapshotArray {
    int** snaparray;
    int* numbers;
    int snap_call=0;
    int lengthofarray;
public:
    SnapshotArray(int length) {
        snaparray=new int*[n];
        numbers=new int[length];
        lengthofarray=length;
        if(numbers==nullptr || snaparray==nullptr)
            exit(-1);

        for(int i=0;i<length;i++){
            numbers[i]=0;
        }
        for(int i=0;i<n;i++){
            snaparray[i]=new int[length];
            for(int j=0;j<length;j++)
                snaparray[i][j]=-1;
        }
    }
    void set(int index, int val) {
        //here we set element at index and snap_id=0 at the start to be val
        numbers[index]=val;
    }
    /*
    here we click picture of the entire array and include them in snaparray
    */
    int snap() {
        //cout<<snap_call<<endl;
        snap_call++;
        for(int i=0;i<lengthofarray;i++)
            snaparray[snap_call-1][i]=numbers[i];
        return snap_call-1;
    }
    
    int get(int index, int snap_id) {
       return snaparray[snap_id][index];
    }
};


int main(){
    SnapshotArray snapshotArr = SnapshotArray(2);
    snapshotArr.set(0,12);  // Set array[0] = 5
    //snapshotArr.set(0,16);  // Set array[0] = 5
    //snapshotArr.set(0,13);  // Set array[0] = 5
    cout<<snapshotArr.snap()<<endl;  // Take a snapshot, return snap_id = 0
    //snapshotArr.set(0,6);
    //cout<<snapshotArr.get(0,0)<<endl;  // Get the value of array[0] with snap_id = 0, return 5
    cout<<snapshotArr.snap()<<endl;  // Take a snapshot, return snap_id = 0
    cout<<snapshotArr.get(1,0)<<endl;  // Get the value of array[0] with snap_id = 0, return 5
    cout<<snapshotArr.get(1,0)<<endl;  // Get the value of array[0] with snap_id = 0, return 5
    cout<<snapshotArr.snap()<<endl;  // Take a snapshot, return snap_id = 0
    // cout<<snapshotArr.snap()<<endl;  // Take a snapshot, return snap_id = 0
    return 0;
}