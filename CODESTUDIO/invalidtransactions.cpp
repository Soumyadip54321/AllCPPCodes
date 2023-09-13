#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> invalid_transactions(vector<vector<int>> &transactions, int n);


int main(){
    vector<vector<int>> invalidtrans;
    vector<vector<int>> transactions={{1,20,100,1},{2,30,24,1},{1,60,90,2}};
    invalidtrans=invalid_transactions(transactions,3);
    return 0;
}
vector<vector<int>> invalid_transactions(vector<vector<int>> &transactions, int n){
    
}