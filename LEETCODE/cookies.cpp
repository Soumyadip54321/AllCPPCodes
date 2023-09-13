#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int distributeCookies(vector<int>& cookies, int k);

int main(){
    vector<int> cookies={6,1,3,2,2,4,1,2};
    cout<<distributeCookies(cookies,3);
    return 0;
}
int distributeCookies(vector<int>& cookies, int k){
    //BRUTE FORCE
    /*
    idea:
    1. we check for all possible distributions to all k children and of those we take that maximum cookie sum 
    that is the minimal
    */
    priority_queue<int> pq;
    

}