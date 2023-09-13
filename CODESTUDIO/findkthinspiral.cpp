#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int findKthElement(vector<vector<int>> matrix, int k);


int main(){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout<<findKthElement(matrix,10);
    return 0;
}
int findKthElement(vector<vector<int>> matrix, int k){
    int lc=0,hc=matrix[0].size()-1,lr=matrix.size()-1,hr=0;
    vector<int> elements;

    while (true)
    {
        for(int i=lc;i<=hc;i++){
            elements.push_back(matrix[hr][i]);
        }
        hr++;

        if(lr<hr)
            break;
        
        for(int i=hr;i<=lr;i++){
            elements.push_back(matrix[i][hc]);
        }
        hc--;
        if(lc>hc)
            break;
        
        for(int i=hc;i>=lc;i--){
            elements.push_back(matrix[lr][i]);
        }
        lr--;
        if(lr<hr)
            break;
        
        for(int i=lr;i>=hr;i--){
            elements.push_back(matrix[i][lc]);
        }
        lc++;
        if(lc>hc)
            break;
    }
    // for(auto val:elements)
    //     cout<<val<<",";
    // cout<<endl;
    return elements[k-1];
}