#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int possibleNumbers(int n, int m, vector<int>& digits);

int main(){
    vector<int> digits={1,4,5};
    cout<<possibleNumbers(3,455,digits);
    return 0;
}
int possibleNumbers(int n, int m, vector<int>& digits){
    string numstr=to_string(m);
    int numdigits=numstr.length();
    int numlessthan=0,numformedwithdigits=1,total=1;

    while (numformedwithdigits<numdigits)
    {
        total*=n;
        numlessthan+=total;
        numformedwithdigits++;
    }
    //we count numdigits less that numstr[0]-'0'
    int numdigitslessthanMSB=0;
    for(int i=0;i<n;i++){
        if(digits[i]>=numstr[0]-'0')
            break;
        else
            numdigitslessthanMSB++;
    }

    //we now compute nos formed with same number of digits but with MSB less than MSB of number
    total=1;
    for(int i=0;i<numdigits-1;i++){
        total*=n;
    }

    for(int i=0;i<numdigitslessthanMSB;i++)
        numlessthan+=total;
    
    //now we compute the sum for numbers that starts with same MSB as is in number
    //we start with position MSB-1 and run till the

    //we find position at which digit < digit at MSB-1 occurs in number
    int posofseclastdigit;
    for(int i=0;i<n;i++){
        posofseclastdigit=i;

        if(digits[i]>numstr[1]-'0')
            break;
    }
    numlessthan+=(posofseclastdigit+1)*n;

    cout<<numlessthan<<endl;
    return 0;
}