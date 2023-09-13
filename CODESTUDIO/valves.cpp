#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long underwaterValves(int n, vector<int> &h);
long long maxBeauty(vector<int> &a, vector<int> &b);
int allBlack(int n, int m, vector<int> &a, vector<vector<int>> &v, vector<int> &b);

int main(){
    vector<int> h={20,2,3,4,1},a={1,0,1},b={2,0};
    vector<vector<int>> tree={{0,1},{0,2}};
    //cout<<underwaterValves(5,h)<<endl;
    //cout<<maxBeauty(a,b)<<endl;
    cout<<allBlack(3,2,a,tree,b)<<endl;
    return 0;
}
long long underwaterValves(int n, vector<int> &h){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int mindistance=0,loc=0;

    for(int i=0;i<n;i++){
        pq.push({h[i],i});
    }

    while (not(pq.empty()))
    {
        mindistance+=abs(loc-pq.top().second);
        loc=pq.top().second;
        pq.pop();
    }
    return mindistance;
}
long long maxBeauty(vector<int> &a, vector<int> &b){
    long long maxbeautysum=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i=0;i<a.size();i++){
        maxbeautysum+=a[i]*b[i];
    }
    return maxbeautysum;
}
int allBlack(int n, int m, vector<int> &a, vector<vector<int>> &v, vector<int> &b)
{
    // Write your code here
    int black=0;

    sort(v.begin(),v.end());
    sort(b.begin(),b.end());

    for(int i=0;i<m;i++){
        for(int j=0;j<v.size();j++){
            if(v[j][1]==b[i]){
                if(a[v[j][1]]==1)
                    a[v[j][1]]=0;
                else
                    a[v[j][1]]=1;
                
                if(a[v[j][0]]==0)
                    a[v[j][0]]=1;
                else
                    a[v[j][0]]=0;
            }
            else{
                if(a[b[i]]==1)
                    a[b[i]]=0;
                else
                    a[b[i]]=1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<",";
    cout<<endl;

    for(int i=0;i<n;i++){
        if(a[i]==1)
            black++;
    }
    return black;
}