#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
string getWinner(vector < string > & votes);

int main(){
    vector < string > votes={"Atul","Atul"};
    cout<<getWinner(votes);
    return 0;
}
string getWinner(vector < string > & votes){
    unordered_map<string,int> votect;
    int highestvt=INT_MIN,candwithhighestvt=0;
    string ans;

    for(auto name:votes)
        votect[name]++;
    
    for(auto n:votect){
        highestvt=max(highestvt,n.second);
    }

    for(auto n:votect){
        if(n.second==highestvt){
            if(ans.empty())
                ans=n.first;
            else{
                if(n.first<ans){
                    ans=n.first;
                }
            }
        }
    }
    return ans;
}