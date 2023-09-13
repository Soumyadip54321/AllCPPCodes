#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int diagonalSum(vector<vector<int>>& mat);
int modulo(string s,int m);

const int N=1e5+10;
long long hsh[N];


int main(){
    vector<vector<int>> matrix={{5}};
    string s="110011101000011010100110110110100111100010111110000100011001000100110010001001001110000011101010101011010110101001011100110101101001111110010011100111101001111001100101100111000011100011000000011011010111001110001101101011101010011011101111101011111100001100101011001000100001100101011110100100010100010110101000000111010110111001111111001010001101010110110000001011100100101010100101001011010001011110111001010011111001111101000101001101010100110001110000000111001100010110010101000010001100100011011010001100000000100110111111010111101001011001100011000100001110011011100010110100011001010101110000101001101011010000000000100110111011000001101110000001100010011010000011011110000111011010001111011000101010110101100110100001011010001000011101101011101001000100110001110010111010110111101001010100011000100110001001010011111110110010001100111000100011000010011100111011111110011011111101010110111100100010101010110100010000011110000010101011100000101";
    int m=44;
    // cout<<diagonalSum(matrix)<<endl;
    cout<<modulo(s,m)<<endl;
    return 0;
}
int diagonalSum(vector<vector<int>>& mat){
    int pd_sum=0,sd_sum=0;

    for(int i=0;i<mat.size();i++)
        pd_sum+=mat[i][i];
    
    for(int i=0;i<mat.size();i++)
        sd_sum+=mat[i][mat.size()-1-i];

    if((mat.size()-1)%2==0)
        return pd_sum+sd_sum-mat[(mat.size()-1)/2][(mat.size()-1)/2];
    return pd_sum+sd_sum;
}
int modulo(string s,int m){
            int n=s.size();
            int p[n];
            p[0]=1;
            for(int i=1;i<n;i++)
                p[i]=(p[i-1]%m * 2%m)%m;
            int ans=0;
            reverse(s.begin(),s.end());
            for(int i=0;i<n;i++)
            {
                int c=s[i]-'0';
                c=(c%m * p[i]%m)%m;
                ans=(ans%m + c%m)%m;
            }
            return ans;
}