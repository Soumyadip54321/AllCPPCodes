#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void computeroundsum(int);

int main(){
    int t;
    cin>>t;

    while (t)
    {
        int num;
        cin>>num;
        computeroundsum(num);
        t--;
    }
    return 0;
}
void computeroundsum(int num){
    vector<int> ans;
    string str=to_string(num);

    for(int i=str.length()-1;i>=0;i--){
        if(str[i]-'0'!=0){
            ans.push_back((str[i]-'0')*pow(10,str.length()-i-1));
        }
    }
    cout<<ans.size()<<endl;

    for(auto val:ans)
        cout<<val<<" ";
    cout<<endl;
}