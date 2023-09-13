#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
long long titleToNumber(string str);


int main(){
    string str="COD";
    cout<<titleToNumber(str)<<endl;
    return 0;
}
long long titleToNumber(string str){
    long long colnum=0;
    int i=0,j=0;

    while (i<str.length())
    {
        colnum+=str[i]-'A'+j;
        j+=25;
        i++;
    }
    return colnum+str.length();
}