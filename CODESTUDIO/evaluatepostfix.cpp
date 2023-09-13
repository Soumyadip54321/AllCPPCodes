#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int M=1e9+7;
int evaluatePostfix(string &exp);
vector<int> maximalANDSubsequences(vector<int> &arr, int k);
void formsubseq(vector<int>,vector<int>,int,int);
vector<vector<int>> allsubofksize;

int main(){
    string exp="2 3 1 * + 9 -";
    vector<int> arr={6,3,7,0},subseqwithmaxandval;
    subseqwithmaxandval=maximalANDSubsequences(arr,4);
    //cout<<evaluatePostfix(exp);
    return 0;
}
int evaluatePostfix(string &exp){
    stack<int> s;
    long long evaluatedsum=0;
    int idx=0;

    for(int i=0;i<=exp.length();i++){
        if((exp[idx]=='*' || exp[idx]=='+' || exp[idx]=='-' || exp[idx]=='/') && (exp[i]==' ' || i==exp.length())){
            long long first_op=s.top();
            s.pop();
            long long sec_op=s.top();
            s.pop();

            if(exp[idx]=='*')
                evaluatedsum=(sec_op*first_op);
            else if(exp[idx]=='+')
                evaluatedsum=(sec_op+first_op);
            else if(exp[idx]=='-')
                evaluatedsum=(sec_op-first_op);
            else
                evaluatedsum=(sec_op/first_op)%M;

            s.push(evaluatedsum);
            idx=i+1;
        }
        else if(exp[i]==' ' && isdigit(exp[idx])){
                string str=exp.substr(idx,i-idx);
                int num=stoi(str);
                s.push(num);
                idx=i+1;
        }
    }
    return s.top()%M;
}
vector<int> maximalANDSubsequences(vector<int> &arr, int k){
    vector<int> v,maxsubseq;
    formsubseq(arr,v,0,k);
    int numsubseqofmaxANDval=0,maxANDval=-1;

    for(int i=0;i<allsubofksize.size();i++){
        int andval=allsubofksize[i][0];
        for(auto val:allsubofksize[i]){
            andval &= val;
        }
        if(andval>maxANDval)
            maxANDval=andval;
    }

    for(int i=0;i<allsubofksize.size();i++){
        int andval=allsubofksize[i][0];
        for(auto val:allsubofksize[i]){
            andval &= val;
        }
        if(andval==maxANDval)
            numsubseqofmaxANDval++;
    }

    //cout<<maxANDval<<" "<<numsubseqofmaxANDval<<endl;
    return {maxANDval,numsubseqofmaxANDval};
}
void formsubseq(vector<int> arr,vector<int> subvec,int idx,int times){
    if(times==0){
        allsubofksize.push_back(subvec);
        return;
    }

    for(int i=idx;i<arr.size();i++){
        subvec.push_back(arr[i]);
        formsubseq(arr,subvec,i+1,times-1);
        subvec.pop_back();      //backtrack;
    }
}