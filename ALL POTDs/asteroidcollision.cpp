#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids);

int main(){
    vector<int> asteroids={1,1,-1,-2},res;
    res=asteroidCollision(asteroids);
    return 0;
}
vector<int> asteroidCollision(vector<int>& asteroids){
    vector<int> res,segasteroids=asteroids;
    stack<int> remasteroids;
    int n=asteroids.size(),i=n-2,j=n-1;

    while (i>=0)
    {
        if(segasteroids[i]>0 && segasteroids[j]<0 && (segasteroids[i]!=0 && segasteroids[j]!=0)){
            if(segasteroids[i]==abs(segasteroids[j])){
                segasteroids[i]=0;
                segasteroids[j]=0;

                if(not(remasteroids.empty())){
                    segasteroids[i]=remasteroids.top();
                    remasteroids.pop();
                }
            }
            else if(segasteroids[i]>abs(segasteroids[j])){
                    segasteroids[j]=0;

                    while(not(remasteroids.empty()) && segasteroids[i]>0){
                        int ast=remasteroids.top();
                        if(segasteroids[i]>abs(ast))
                            remasteroids.pop();
                        else if(segasteroids[i]==abs(ast)){
                            segasteroids[i]=0;
                            remasteroids.pop();
                        }
                        else{
                            segasteroids[i]=0;
                        }
                    }
                    if(not(remasteroids.empty())){
                        while (not(remasteroids.empty()))
                        {
                            segasteroids[i]=remasteroids.top();
                            remasteroids.pop();
                            i++;
                        }
                    }
            }
            else{
                segasteroids[i]=0;
                swap(segasteroids[i],segasteroids[j]);
            }
        }
        else if(segasteroids[i]<0 && segasteroids[j]<0 && (segasteroids[i]!=0 && segasteroids[j]!=0)){
            remasteroids.push(segasteroids[j]);
            segasteroids[j]=0;
        }
        j=i;
        i--;
        
    }

    //here we check if stack's not empty we put the vales back
    if(not(remasteroids.empty())){
        int bp;
        for(int i=0;i<n;i++){
            if(segasteroids[i]==0){
                bp=i;
                break;
            }
        }
        while (not(remasteroids.empty()))
        {
            segasteroids[bp]=remasteroids.top();
            remasteroids.pop();
            bp++;
        }
    }
    for(auto val:segasteroids){
        if(val!=0)
            res.push_back(val);
    }
    return res;
}