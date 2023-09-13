#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

string kthPermutation(int n, int k);

vector<string> allperm;

int main(){
    cout<<kthPermutation(3,5);
    return 0;
}
string kthPermutation(int n, int k){
    string ans="";
    vector<int> number;
    int fact=1;

    for(int i=1;i<n;i++){
        fact*=i;
        number.push_back(i);
    }
    number.push_back(n);
    k-=1;

    while (true)
    {
        ans+=to_string(number[k/fact]);
        number.erase(number.begin()+(k/fact));
        if(number.empty())
            break;
        k=k%fact;
        fact=fact/number.size();
    }
    return ans;
}
