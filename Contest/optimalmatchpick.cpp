#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int minimumCardPickup(vector<int>& cards);

int main(){
    vector<int> cards={3,4,2,3,4,7,3};
    cout<<minimumCardPickup(cards)<<endl;
    return 0;
}
int minimumCardPickup(vector<int>& cards){
    int minlengthpair=1e5+10;
    unordered_map<int,pair<int,int>> m;

    for(int i=0;i<cards.size();i++){
        if(m[cards[i]].first==1){
            minlengthpair=min(minlengthpair,i-m[cards[i]].second+1);
        }
        else
            m[cards[i]].first++;        //contains the count
        m[cards[i]].second=i;       //contains the index
    }
    if(minlengthpair==1e5+10)
        return -1;
    return minlengthpair;
}
