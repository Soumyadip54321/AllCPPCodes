#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
vector<long long> createSequence(long long n);

int main(){
    vector<long long> seq;
    seq=createSequence(11332);
    return 0;
}
vector<long long> createSequence(long long n){
    /*
    idea:
    1. we form all nos with 2s and 5s only in them respectively at first
    2. Such nos are obtained when multiplied with 1/11/111/.... and so on
    3. we hence multiply each time with such a no post checking if such a seq of 1s exceeds n or not
    */

   //set<long long> twosandfives;
   vector<long long> twosandfives;
    if(2<=n)
        twosandfives.push_back(2);
    if(5<=n)
        twosandfives.push_back(5);
    long long idx=0;

    while(true){
        if(twosandfives[idx]*10+2<=n)
            twosandfives.push_back(twosandfives[idx]*10+2);
        else
            break;
        
        if(twosandfives[idx]*10+5<=n)
            twosandfives.push_back(twosandfives[idx]*10+5);
        else
            break;
        idx++;
    }

    // for(auto n:twosandfives)
    //     cout<<n<<",";
    // cout<<endl;
    return twosandfives;
}