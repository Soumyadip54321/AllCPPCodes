#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void insert(queue<int> &q, int k);
int findFrequency(queue<int> &q, int k);



int main(){
    queue<int> q;
    int m,n;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        insert(q,num);
    }
    queue<int> temp=q;

    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        cout<<findFrequency(q,k);
        q=temp;
    }

    return 0;
}
void insert(queue<int> &q, int k){
    q.push(k);
}
int findFrequency(queue<int> &q, int k){
    int numfreq=0;
    while (not(q.empty()))
    {
        if(q.front()==k)
            numfreq++;
        q.pop();
    }
    // if(numfreq==0)
    //     return -1;
    return numfreq;
}