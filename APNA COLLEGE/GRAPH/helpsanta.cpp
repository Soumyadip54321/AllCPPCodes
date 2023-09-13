#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int helpSanta(int n, int m, vector<vector<int>> &g);
void dfs(int,int&);
int findkprime(int);
void setprimes();


const int N=1e4;
bool visited[N];
vector<int> adjmtx[N];
vector<bool> isprime(N,1);

int main(){
    vector<vector<int>> g={{1,2},{2,3},{3,4},{4,5},{6,7},{9,10}};
    setprimes();
    cout<<helpSanta(10,6,g)<<endl;
    return 0;
}
int helpSanta(int n, int m, vector<vector<int>> &g){
    /*idea: 1. we apply dfs/bfs to count the maximum child and insert it into a priority queue
            2. Then we consider the root value and find its corresponding prime number and return*/
    int maxconnections=-1,maxconnect=0,ct=0;

    for(int i=0;i<m;i++){
        adjmtx[g[i][0]].push_back(g[i][1]);
        adjmtx[g[i][1]].push_back(g[i][0]);
    }

    for(int i=1;i<=n;i++){
        if(not(visited[i])){
            dfs(i,maxconnect);
            maxconnections=max(maxconnections,maxconnect);
            maxconnect=0;
        }
    }
    //cout<<maxconnections<<endl;
    for(int i=2;i<N;i++){
        if(isprime[i])
            ct++;
        if(ct==maxconnections)
            return i;
    }
    return -1;
}
void dfs(int vertex,int& maxconnect){
    visited[vertex]=true;
    maxconnect++;

    for(auto child:adjmtx[vertex]){
        if(visited[child])
            continue;
        dfs(child,maxconnect);
    }
}
void setprimes(){
    /*here we apply sieve of eratosthenes to set all primes till 1e5*/
    isprime[0]=isprime[1]=false;

    for(int i=2;i<N;i++){
        if(isprime[i]==true){
            for(int j=i*i;j<N;j+=i)
                isprime[j]=false;
        }
    }

    /*TC=N(LOG(LOG(N)))
        =N(N/2+N/3+N/4+N/5+.......+N/N)---> this without if statement
        =N(LOG(N))
        with if,
        =N(N/2+N/3+N/5+N/7+....)
        =N(LOG(LOG(N)))
    */
}