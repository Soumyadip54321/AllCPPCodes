#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> anagramMapping(int n, vector<int> a, vector<int> b);
vector<vector<int>> sumOfKxKMatrices(vector<vector<int>> &arr, int k);
int calculateSquare(int num);
string addBinaryString(string &a, string &b, int n, int m);

int main(){
    vector<int> a={10,20,30,40,50},b={20,10,40,50,30},v;
    vector<vector<int>> ksum,arr={{5,7},{8,1}};
    string s="10000",p="1001";
    cout<<addBinaryString(s,p,5,4);
    //v=anagramMapping(5,a,b);
    //ksum=sumOfKxKMatrices(arr,2);
    // cout<<calculateSquare(9)<<endl;

    // for(int i=0;i<ksum.size();i++){
    //     cout<<"{";
    //     for(auto val:ksum[i]){
    //         cout<<val<<",";
    //     }
    //     cout<<"}"<<endl;
    // }
    return 0;
}
vector<int> anagramMapping(int n, vector<int> a, vector<int> b){
    vector<int> indexinanagram;
    unordered_map<int,int> anagramidx;

    for(int i=0;i<n;i++){
        anagramidx[b[i]]=i;
    }
    for(auto val:a){
        indexinanagram.push_back(anagramidx[val]);
    }
    return indexinanagram;
}
vector<vector<int>> sumOfKxKMatrices(vector<vector<int>> &arr, int k){
    /*
    idea:
    1. we maintain 4 ptrs:-
        (i). 2 in rows and 2 in columns
    */
    int sum=0;
    vector<vector<int>> subarrsum;
    if(k==arr.size()){
        for(int r=0;r<k;r++){
            for(int c=0;c<k;c++){
                sum+=arr[r][c];
            }
        }
        subarrsum.push_back({sum});
        return subarrsum;
    }

    for(int r1=0;r1<=arr.size()-k;r1++){
        vector<int> rowsum;

        for(int c1=0;c1<=arr.size()-k;c1++){
            int r2=r1;
            int c2=c1;
            sum=0;
            do
            {
                sum+=arr[r2][c2];
                c2++;

                if(c2>=c1+k){
                    c2=c1;
                    r2++;
                }
            }while (r2<r1+k);
            rowsum.push_back(sum);
        }
        subarrsum.push_back(rowsum);
    }
    return subarrsum;

    //TC=O(N^3)
}

int calculateSquare(int num)
{
    //    Write your code here.
    int numsquare=0;

    if(num<0)
        num*=-1;
   for(int i=0;i<num;i++){
       numsquare+=num;
   }
   if(numsquare<0)
        numsquare*=-1;
        
    return numsquare;
}
string addBinaryString(string &a, string &b, int n, int m){
    string ans="";
    string larger,smaller;

    if(n>=m){
        larger=a;
        smaller=b;
    }
    else{
        larger=b;
        smaller=a;
    }
    reverse(larger.begin(),larger.end());
    reverse(smaller.begin(),smaller.end());
    int carry=0;
    int diff=abs(n-m);

    for(int i=0;i<smaller.length();i++){
        if((smaller[i]-'0')+(larger[i]-'0')+carry==1){
            ans+=1+'0';
            carry=0;
        }
        else if((smaller[i]-'0')+(larger[i]-'0')+carry==2){
            ans+=0+'0';
            carry=1;
        }
        else if((smaller[i]-'0')+(larger[i]-'0')+carry==0){
            ans+=0+'0';
            carry=0;
        }
        else{
            ans+=1+'0';
            carry=1;
        }
    }

    for(int i=smaller.length();i<larger.length();i++){
        if(larger[i]-'0'+carry==0){
            ans+=0+'0';
            carry=0;
        }
        else if(larger[i]-'0'+carry==1){
            ans+=1+'0';
            carry=0;
        }
        else{
            ans+=0+'0';
            carry=1;
        }
    }

    if(carry){
        ans+=carry+'0';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}