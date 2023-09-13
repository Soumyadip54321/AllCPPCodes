#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getAverages(vector<int>& nums, int k);


int main(){
    vector<int> nums={18334,25764,19780,92480,69842,73255,89893},avg;
    avg=getAverages(nums,0);
    return 0;
}
vector<int> getAverages(vector<int>& nums, int k){
    /*
    idea:
    1. here we maintain 3 ptr:- L,R,C=> left,right,centre
    2. they all initially point at index=0
    3. if C=L+K && C=R-K we compute sum else we push -1 into the array
    4. at every step from the first sum computed we deduct the value at the L ptr and add value at new R ptr
    */
   int L=0,R=0,C=0;
   long long sumofele=0;
   vector<int> kavg;

   while (C<L+k && C<nums.size())
   {
        kavg.push_back(-1);
        C++;
   }
    //cout<<C<<endl;
    if(C==nums.size())
        return kavg;
        
    if(nums.size()-C-1<k){
            for(int i=C;i<nums.size();i++)
                kavg.push_back(-1);
            return kavg;
    }
    R=C+k;

    for(int i=L;i<=R;i++)
        sumofele+=nums[i];
    
    kavg.push_back(sumofele/(2*k+1));

    for(int i=R+1;i<nums.size();i++){
        sumofele=sumofele-nums[L]+nums[i];
        kavg.push_back(sumofele/(2*k+1));
        L++;
    }
    C=nums.size()-k;

    for(int i=C;i<nums.size();i++)
        kavg.push_back(-1);

    for(auto val:kavg)
        cout<<val<<",";
    cout<<endl;

    return kavg;

    /*TC=O(N)*/
}