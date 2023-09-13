#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string longestCommonPrefix (string arr[], int N);


int main(){
    string arr[]={"abcdefghij", "abcdefghi","abcdef"};
    cout<<longestCommonPrefix(arr,3)<<endl;
    return 0;
}
string longestCommonPrefix (string arr[], int N){
    string exppre,commonpre="";

    if(N==1)
        return arr[0];

    for(int i=0;i<N-1;i++){
        if(arr[i].length()<=arr[i+1].length())
            exppre=arr[i];
        else
            exppre=arr[i+1];
    }

    //cout<<exppre<<endl;

    for(int i=0;i<N;i++){
        int j=0;
        while (j<exppre.length() && exppre[j]==arr[i][j])
        {
            commonpre+=exppre[j];
            j++;
        }
        if(commonpre=="")
            return "-1";
        exppre=commonpre;
        commonpre="";
    }
    return exppre;
}