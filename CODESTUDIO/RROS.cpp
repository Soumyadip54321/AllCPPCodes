#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
// #include <unordered_map>
using namespace std;
vector<int> roundRobin(vector<int> &process, int n, int quantum);
int at[200];
int tat[200];


int main(){
    vector<int> process={5,4,3},wt;
    wt=roundRobin(process,3,2);
    return 0;
}
vector<int> roundRobin(vector<int> &process, int n, int quantum){
    vector<int> gantt;
    vector<int> bt=process;
    int i,time=0;

    for(i=0;i<n;i++)
        gantt.push_back(0);
    
    i=0;
    while (i<n)
    {
        for(int j=i;j<n;j++){

            if(bt[j]>0){
                if(bt[j]>quantum){
                    bt[j]-=quantum;
                    time+=quantum;
                }
                else{
                    time+=bt[j];
                    bt[j]=0;
                }
                gantt[j]=time;
            }
        }
        if(bt[i]==0)
            i++;
    }
    for(i=0;i<n;i++){
        gantt[i]-=process[i];
    }
    return gantt;
}