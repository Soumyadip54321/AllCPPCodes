#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int n=1e6+10;

class MyHashSet {
    int *hshset;
public:
    MyHashSet() {
        hshset=(int*)malloc(sizeof(int)*n);
        if(hshset==nullptr)
            exit(-1);
        
        for(int i=0;i<n;i++)
            hshset[i]=0;
    }
    
    void add(int key) {
        hshset[key]++;
    }
    
    void remove(int key) {
        hshset[key]=0;
    }
    
    bool contains(int key) {
        if(hshset[key]>0)
            return true;
        return false;
    }
};


int main(){
    MyHashSet myHashSet;      //sets up a hash set
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    cout<<myHashSet.contains(1)<<endl; // return True
    cout<<myHashSet.contains(3)<<endl; // return False, (not found)
    myHashSet.add(2);  // set = [1, 2]
    cout<<myHashSet.contains(2)<<endl; // return True
    myHashSet.remove(2);  // set = [1]
    cout<<myHashSet.contains(2)<<endl; // return False, (already removed)
    return 0;
}