#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAX 1000
using namespace std;

int findK(int a[MAX][MAX],int n,int m,int k);

int main(){
    int a[MAX][MAX]={{1,  2,  3,  4},
                     {5 , 6,  7,  8},
                     {9,  10, 11, 12},
                     {13, 14, 15, 16}};
    cout<<findK(a,4,4,10);
    return 0;
}
int findK(int a[MAX][MAX],int n,int m,int k){
    int rl=0,rh=n-1,cl=0,ch=m-1;
    vector<int> spiralitems;

    while (true)
    {
        //forward
        for(int i=cl;i<=ch;i++){
            spiralitems.push_back(a[rl][i]);
        }
        rl++;
        if(rl>rh)
            break;
        //downward
        for(int i=rl;i<=rh;i++)
            spiralitems.push_back(a[i][ch]);
        ch--;
        if(cl>ch)
            break;
        
        //backward
        for(int i=ch;i>=cl;i--)
            spiralitems.push_back(a[rh][i]);
        rh--;
        if(rl>rh)
            break;
        
        //upward
        for(int i=rh;i>=rl;i--)
            spiralitems.push_back(a[i][cl]);
        cl++;
        if(cl>ch)
            break;
    }
    
    // for(auto val:spiralitems)
    //     cout<<val<<",";
    // cout<<endl;
    return spiralitems[k-1];
}