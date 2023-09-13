#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int buyChoco(vector<int>& prices, int money);
int minExtraChar(string s, vector<string>& dictionary);
long long maxStrength(vector<int>& nums);

int main(){
    vector<int> prices={3,2,3},nums={-9};
    vector<string> dictionary={"na","i","edd","wobow","kecv","b","n","or","jj","zul","vk","yeb","qnfac","azv","grtjba","yswmjn","xowio","u","xi","pcmatm","maqnv"};
    string s="azvzulhlwxwobowijiyebeaskecvtjqwkmaqnvnaomaqnvf";
    //cout<<buyChoco(prices,3)<<endl;
    //cout<<minExtraChar(s,dictionary)<<endl;
    cout<<maxStrength(nums)<<endl;
    return 0;
}
int buyChoco(vector<int>& prices, int money){
    /*idea: 1. first we sort prices
            2. then we compute appeal of each */
    sort(prices.begin(),prices.end());
    if(money-(prices[0]+prices[1])<0)
        return money;
    return money-(prices[0]+prices[1]);
}
int minExtraChar(string s, vector<string>& dictionary){
    string new_string="",modstring;
    vector<pair<int,string>> v;

    for(int i=0;i<dictionary.size();i++)
        v.push_back(make_pair(dictionary[i].length(),dictionary[i]));
    
    sort(v.rbegin(),v.rend());
    

    for(int i=0;i<v.size();i++){
        while(s.find(v[i].second)!=string::npos){
            new_string=s.substr(0,s.find(v[i].second))+s.substr(s.find(v[i].second)+v[i].second.length());
            s=new_string;
            cout<<s<<endl;
        }
    }
    for(int i=0;i<new_string.length();i++)
        cout<<new_string[i];
    cout<<endl;
    return new_string.length();
}
long long maxStrength(vector<int>& nums){
    /*idea is to multiply all positive strength entries with even number of largest negative entries*/
    vector<int> maximums;
    long long maxstrength=1;

    if(nums.size()==1)
        return nums[0];

    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            maximums.push_back(nums[i]);
        }
    }
    sort(maximums.begin(),maximums.end());
    if(maximums.size()%2==0){
        for(auto val:maximums)
            maxstrength*=val;
    }
    else{
        for(int i=0;i<maximums.size()-1;i++)
            maxstrength*=maximums[i];
    }

    maximums.clear();
    for(int i=0;i<nums.size();i++){
        if(nums[i]>=0){
            maximums.push_back(nums[i]);
        }
    }

    if(maxstrength!=1){
        for(int i=0;i<maximums.size();i++){
            if(maximums[i]!=0)
                maxstrength*=maximums[i];
        }
    }
    else{
        if(maximums.size()==1)
            maxstrength*=maximums[0];
        else{
            for(auto val:maximums){
                if(val!=0)
                    maxstrength*=val;
            }
        }
    }
    return maxstrength;
}