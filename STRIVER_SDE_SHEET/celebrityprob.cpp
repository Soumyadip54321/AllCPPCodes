#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int celebrity(vector<vector<int> >& M, int n); 

int main(){
    vector<vector<int> > M={{0,1,0},
                            {0,0,0},
                            {0,1,0}};
    cout<<celebrity(M,3);
    return 0;
}
int celebrity(vector<vector<int> >& M, int n) {
        vector<int> celebrity(n,0);
        int ctcelebrity=0,knownct=0,celebpos;
        //fisrt we find out number of celebrities present at the party
        
        //if there exists >1 we return -1 since not all people at the party will know the celebrities then
        for(int i=0;i<n;i++){
            if(M[i]==celebrity){
                ctcelebrity++;
                celebpos=i;
            }
        }
        if(ctcelebrity>1 or ctcelebrity==0)
            return -1;

        //if there is a celebrity except him/her everyone else must know 
        for(int i=0;i<n;i++){
            if(not(i==celebpos)){
                if(M[i][celebpos])
                    knownct++;
            }
        }
        if(knownct==n-1)
            return celebpos;
        return -1;
}