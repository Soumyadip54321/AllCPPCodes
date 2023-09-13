#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> checkIfPossible(int n);
vector<int> findMin(int n, int q, vector<int> &gain, vector<int> &loss, vector<int> &query);
int findmindays(vector<vector<int>>,vector<int>,int);
vector<int> diff;


int main(){
    vector<int> v,gain={1,2,3,4,5},loss={0,0,0,0,0},query={5,9,8,11,17};
    // v=checkIfPossible(100);
    v=findMin(5,5,gain,loss,query);
    for(auto item:v)
        cout<<item<<" ";
    cout<<endl;
    return 0;
}
vector<int> checkIfPossible(int n){
    vector<int> numbers;
    int i=-1;
    
    do
    {
        i++;
        diff.push_back(n-i);
    }while(n-i>0);

    for(int i=0;i<diff.size();i++){
        if(pow(3,diff[i])<=pow(10,9) && pow(2,i)<=pow(10,9)){
            numbers.push_back(pow(2,i));
            numbers.push_back(pow(3,diff[i]));
            return numbers;
        }
    }
    numbers.push_back(-1);
    return numbers;
}
vector<int> findMin(int n, int q, vector<int> &gain, vector<int> &loss, vector<int> &query){
    vector<vector<int>> gain_loss;
    vector<int> mindays;

    for(int i=0;i<gain.size();i++){
        gain_loss.push_back({gain[i],loss[i]});
    }
    sort(gain_loss.rbegin(),gain_loss.rend());

    for(int i=0;i<q;i++)
        mindays.push_back(findmindays(gain_loss,query,i));
    return mindays;
}
int findmindays(vector<vector<int>> gain_loss,vector<int> query,int idx){
    
    int weight_gained=0,count=0;

    for(int i=0;i<gain_loss.size();i++){
        count++;
        weight_gained+=gain_loss[i][0]-gain_loss[i][1];
        cout<<gain_loss[i][0]<<gain_loss[i][1]<<endl;

        if(weight_gained>=query[idx]){
            cout<<"returned"<<endl;
            return count;
        }
    }
    return -1;
}
