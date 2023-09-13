#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
void deleteMid(stack<int>&s, int sizeOfStack);

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    //s.push(50);

    deleteMid(s,4);
    return 0;   
}
void deleteMid(stack<int>&s, int sizeOfStack){
    //stack is 1-indexed
    int mid=(sizeOfStack%2)+(sizeOfStack/2),n=sizeOfStack,stop=sizeOfStack;
    vector<int> remitems;

    while (stop)
    {
        if(stop!=mid){
            int num=s.top();
            remitems.push_back(num);
        }
        s.pop();
        stop--;
    }

    for(int i=remitems.size()-1;i>=0;i--){
        s.push(remitems[i]);
    }

    // while (not(s.empty()))
    // {
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }
}