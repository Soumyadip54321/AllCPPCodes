#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
double knightProbability(int n, int k, int row, int column);

int main(){
    cout<<knightProbability(8,30,6,4);
    return 0;
}
double knightProbability(int n, int k, int row, int column){
    /*
    idea:
    1. we apply BFS from (r,c) to move to all possible directions
    2. at the end when k=0 we count the number of squares the knight can be in
    3. probability=(1/8)^k*(num squares)
    */
   queue<pair<pair<int,int>,pair<double,int>>> q;     //form:((r,c),(p,level))
   q.push({{row,column},{1.0,k}});

   int xdir[]={2,2,1,-1,-2,-2,-1,1};
   int ydir[]={1,-1,-2,-2,-1,1,2,2};

   while (not(q.empty()))
   {
        int level=q.front().second.second;
        int size=q.size();

        if(level==0)
            break;

        for(int i=0;i<size;i++){
            double prob=q.front().second.first;
            int x=q.front().first.first;
            int y=q.front().first.second;
            q.pop();

            for(int i=0;i<8;i++){
                if((x+xdir[i]>=0 && x+xdir[i]<n) && (y+ydir[i]>=0 && y+ydir[i]<n)){
                    q.push({{x+xdir[i],y+ydir[i]},{(prob*1.0)/8.0,level-1}});
                }
            }
        }
   }


   //here we count the number of squares the knight can move to without going off board
   double p=0.0;
   int ctsquares=0;

    if(not(q.empty()))
        p=q.front().second.first;
    
    while (not(q.empty()))
    {
        ctsquares++;
        q.pop();
    }
    return p*ctsquares;
}