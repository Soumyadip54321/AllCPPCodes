#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> theOrder(int n);

const int n=1e5+10;
int questions[n];
vector<int> sequence;

int main(){
    vector<int> order;
    order=theOrder(46);
    return 0;
}
vector<int> theOrder(int n){
    int numquestionsdone=0,q=2,jump=2,prevq=0;
    if(n==1)
        return {1};

    for(int i=1;i<=n;i++){
        questions[i]=i;
    }

    /* here after nth question ques 1 is arrived at
        so if 1 isn't done then we complete all odd num questions*/
    while (numquestionsdone!=n)
    {
        if(q<=n){
            if(questions[q]>0 && prevq+2==q){
                sequence.push_back(q);
                questions[q]=0;     //indicates visited
                prevq=q;
                q+=1;
                numquestionsdone++;
            }
            else{
                q+=1;
            }
        }
        else{
            q=q%n;
            prevq=-1;
            //n-=numquestionsdone;
        }
    }
    
    for(auto ques:sequence)
        cout<<ques<<",";
    cout<<endl;
    return sequence;
}
