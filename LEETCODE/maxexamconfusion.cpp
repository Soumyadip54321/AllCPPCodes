#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int maxConsecutiveAnswers(string answerKey, int k);

int main(){
    string answerKey="TTFTTFTT";
    cout<<maxConsecutiveAnswers(answerKey,1);
    return 0;
}
int maxConsecutiveAnswers(string answerKey, int k){
    char tochange;
    int tochangeidx,start=0,timeschange=k,maxchange1=-1,maxchange2=-1,changes=0;

    if(answerKey[0]=='F')
        tochange='T';
    else
        tochange='F';
    
    if(answerKey[start]!=tochange){
        while (start<answerKey.length())
        {
            if(answerKey[start]==tochange){
                changes++;
                start++;
            }
            else{
                timeschange--;
                start++;

                if(timeschange<0){
                    start=tochangeidx;
                    timeschange=k;
                    changes=0;
                    continue;
                }
                else{
                    if(timeschange==k-1)
                        tochangeidx=start;
                    changes++;
                }
            }
            maxchange1=max(maxchange1,changes);
        }
    }

    changes=0;
    timeschange=k;
    start=0;
    tochange=answerKey[0];
    while (start<answerKey.length())
    {
        if(answerKey[start]==tochange){
            changes++;
            start++;
        }
        else{
            timeschange--;
            start++;

            if(timeschange<0){
                start=tochangeidx;
                timeschange=k;
                changes=0;
                continue;
            }
            else{
                if(timeschange==k-1)
                    tochangeidx=start;
                changes++;
            }
        }
        maxchange2=max(maxchange2,changes);
    }
    cout<<maxchange1<<" "<<maxchange2<<endl;
    return max(maxchange1,maxchange2);
}