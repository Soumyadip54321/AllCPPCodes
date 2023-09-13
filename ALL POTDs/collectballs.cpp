#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int collectBalls(int N);
int minsteps(int,int,int,int);
int steps=INT_MAX;

int main(){
    cout<<collectBalls(9);
    return 0;
}
int collectBalls(int N){
    //at start box has 1 ball in it
    minsteps(1,N-1,0);
    // cout<<steps<<endl;
    return steps;
}
int minsteps(int ballsinbox,int target,int counterread){
    if(target==ballsinbox){
        return;
    }
    int op1steps,op2steps;
    //reset counter with balls in box
   if(counterread!=ballsinbox){
        if(ballsinbox+counterread>target)
            op1steps=1+minsteps(ballsinbox,target,counterread-(target-ballsinbox));
            
        op1steps=1+minsteps(ballsinbox,target,ballsinbox);
   }
   op2steps=1+minsteps(ballsinbox+counterread,target,counterread);

}