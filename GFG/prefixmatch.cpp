#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int klengthpref(string arr[], int n, int k, string str);

int main(){
    string arr[]= {“abba”, “abbb”, “abbc”, “abbd”, “abaa”, “abca”};
    string str="abbg";
    cout<<klengthpref(arr,6,3,str);
    return 0;
}
int klengthpref(string arr[], int n, int k, string str){
    string prefix="";
    int prect=0;

    for(int i=0;i<k;i++)
        prefix+=str[i];
    
    for(int i=0;i<n;i++){
        if(arr[i].length()>=k){
            if(arr[i].substr(0,k)==prefix)
                prect++;
        }
    }
    return prect;
}