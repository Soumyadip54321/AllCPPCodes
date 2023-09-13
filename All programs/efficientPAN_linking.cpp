#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

void efficient_PAN_link(long long);


int main(){
    int testcases;
    cin>>testcases;

    while(testcases!=0){                
        long long applications;
        cin>>applications;
        efficient_PAN_link(applications);
        testcases--;
    }
    return 0;
}
void efficient_PAN_link(long long applications){
    long long num_officers=static_cast<long long>(20);
    // long long each_officer_process_rate=(applications/num_officers);
    long long unprocessed=applications%num_officers;
    cout<<unprocessed<<endl;
}