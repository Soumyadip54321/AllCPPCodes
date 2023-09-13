#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
long long finalvalueofX(vector<string>);

int main(){
    int n;
    long long ans;
    vector<string> statements;
    cin>>n;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        statements.push_back(s);
    }
    cout<<finalvalueofX(statements)<<endl;
    return 0;
}
long long finalvalueofX(vector<string> v){
    long long X=0;
    
    for(int i=0;i<v.size();i++){
        if(v[i][0]=='+' or v[i][2]=='+')
            X++;
        else
            X--;
    }
    return X;
}