#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int findNumber(int n);
int numberstoadd(vector<int>,int);

const int N=1e8+10;
bool digitspresent[N];

int main(){
    cout<<findNumber(790);
    return 0;
}
int findNumber(int n){

    int numct=6;
    for(int i=0;i<6;i++)
        digitspresent[i]=true;
    
    if(n<=6)
    {
        return n-1;
    }
    
    for(int i=6;i<N;i++){
        string num=to_string(i);
        bool found=true;

        for(int j=0;j<num.length();j++){
            if(digitspresent[num[j]-'0']==false){
                found=false;
                break;
            }
        }
        if(found)
            digitspresent[stoi(num)]=true;
    }

    n-=6;
    int start=5;
    do
    {
        start++;
        if(digitspresent[start])
            n--;
    }while (n);

    return start;
}