#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool stoneGame(vector<int>& piles);
string stoneGameIII(vector<int>& stoneValue);
int turnscores(vector<int>&,int);

const int n=1e5+10;
int tripletscores[n];

int main(){
    vector<int> piles={3,7,2,3},stoneValue={-1,-2,-3};
    //cout<<stoneGame(piles)<<endl;
    cout<<stoneGameIII(stoneValue)<<endl;
    return 0;
}
bool stoneGame(vector<int>& piles){
    int Ascore=0,Bscore=0,turn=0;
    /*TC=O(N)*/
    int st=0,e=piles.size()-1,maxpile=0;
    while (st<e)
    {
        maxpile=max(piles[st],piles[e]);
        if(turn%2==0){
            Ascore+=maxpile;
        }
        else
            Bscore+=maxpile;
        if(maxpile==piles[st])
            st++;
        else
            e--;
        turn++;
    }
    if(Ascore>Bscore)
        return true;
    return false;
}
string stoneGameIII(vector<int>& stoneValue){
    /*idea: we compute the sum of piles for 3 consecutive values each and have Alice/Bob pick the maximum of those
    and adding the value to their scores resp until finally comparing their scores*/

    int Ascore=0,Bscore=0,turn=0,sum=0;
    // for(int i=0;i<stoneValue.size();i++){
    //     if(i%3==0)
    //         sum=0;
    //     sum+=stoneValue[i];
    //     tripletscores[i]=sum;
    // }

    int i=0,turnmaxscore=-10000;
    while (i<stoneValue.size())
    {
        turnmaxscore=max(turnmaxscore,stoneValue[i]);
        if(i+1<stoneValue.size())
            turnmaxscore=max(turnmaxscore,stoneValue[i]+stoneValue[i+1]);
        if(i+2<stoneValue.size())
            turnmaxscore=max(turnmaxscore,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]);

        if(turn%2==0)
            Ascore+=turnmaxscore;
        else
            Bscore+=turnmaxscore;

        if(turnmaxscore==stoneValue[i])
            i++;
        else if(turnmaxscore==stoneValue[i]+stoneValue[i+1])
            i+=2;
        else
            i+=3;
        turn++;
        turnmaxscore=-10000;
    }

    cout<<Ascore<<","<<Bscore<<endl;
    if(Ascore==Bscore)
        return "TIE";
    else if(Ascore>Bscore)
        return "ALICE";
    return "BOB";
}
