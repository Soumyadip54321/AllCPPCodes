#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N=1e5+10;
// int prefix_sum[N][N];
int arr[N][N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            // prefix_sum[i][j]=arr[i][j]+prefix_sum[i][j-1]+prefix_sum[i-1][j]-prefix_sum[i-1][j-1];
        }
    }
    int q;
    cin>>q;
    while (q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        long long sum=0;
        // cout<<prefix_sum[c][d]-prefix_sum[c][b-1]-prefix_sum[a-1][d]+prefix_sum[a-1][b-1];
        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++){
                sum+=arr[i][j];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}