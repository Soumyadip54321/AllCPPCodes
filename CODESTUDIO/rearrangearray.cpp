#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> rearrangeArray(vector<int> &A, int m);
string electionResult(string voters);

int main(){
    vector<int> A={1,2,3},arranged;
    string str="-AB-AA--A--BBB-----BA";
    //arranged=rearrangeArray(A,3);
    cout<<electionResult(str);
    return 0;   
}
vector<int> rearrangeArray(vector<int> &A, int m){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;      //form: {diff,index}
    vector<int> arranged;

    for(int i=0;i<A.size();i++){
        pq.push({abs(A[i]-m),i});
    }

    while (not(pq.empty()))
    {
        arranged.push_back(A[pq.top().second]);
        pq.pop();
    }
    return arranged;
}   
string electionResult(string voters){
    //we use 2 ptr approach
    int n=voters.length();
    int Bpos=0,Apos=n-1;
    int Bvotes=0,Avotes=0;

    while (voters[Bpos]!='B' && Bpos<n)
    {
        Avotes++;
        Bpos++;
    }
    while (voters[Apos]!='A' && Apos>=0)
    {
        Bvotes++;
        Apos--;
    }
    Avotes++;
    Bvotes++;

    Bpos++;
    Apos--;
    while (Bpos<Apos )
    {
        Bvotes++;
        Avotes++;
        Bpos++;
        Apos--;
    }

    if(Bvotes==Avotes)
        return "coalition";
    else if(Bvotes>Avotes)
        return "B";
    return "A";
}