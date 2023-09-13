#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

bool PredictTheWinner(vector<int>& nums);
bool predictmaxscores(vector<int>,int,int,int,int);
int checkmaxdiff(vector<int>,int,int,int,int);

int main(){
    vector<int> nums={5,2,3,9};
    cout<<PredictTheWinner(nums);
    return 0;
}
bool PredictTheWinner(vector<int>& nums){
    int p1sc=0,p2sc=0,n=nums.size();
    return predictmaxscores(nums,p1sc,p2sc,0,n-1);
}
bool predictmaxscores(vector<int> nums,int p1sc,int p2sc,int c1,int c2){
    
    //p1 take 1st & p2 check which to pick to maximise difference
    int idx,p1select,p2select;

    if(p1sc==0){
        p1select=nums[c1];
        c1++;
        cout<<p1sc+p1select<<endl;
    }
    else{
        p1select=nums[idx];
        if(c1<c2){
            idx=checkmaxdiff(nums,p2sc,p1sc,c1,c2);
            if(idx==c1)
                c1=idx+1;
            else
                c2=idx-1;
        }
        else if(c1==c2){

            cout<<p1sc+p1select<<" "<<p2sc+p2select<<endl;
            return p1sc+p1select>=p2select;
        }
    }
    //player2
    idx=checkmaxdiff(nums,p2sc,p1sc+p1select,c1,c2);
    p2select=nums[idx];

    if(c1==c2){
        cout<<p1sc+p1select<<" "<<p2sc+p2select<<endl;
        return p1sc+p1select>=p2select+p2sc;
    }

    if(idx==c1){
        cout<<p2sc+p2select<<endl;
        if(predictmaxscores(nums,p1sc+p1select,p2sc+p2select,idx+1,c2))
            return true;
    }
    else{
        cout<<p2sc+p2select<<endl;
        if(predictmaxscores(nums,p1sc+p1select,p2sc+p2select,c1,idx-1))
            return true;
    }

    return false;
}
int checkmaxdiff(vector<int> nums,int score1,int score2,int start,int end){
    if(start==end)
        return start;

    if(abs(score1+nums[start]-score2)<=abs(score1+nums[end]-score2))
        return start;

    return end;
}