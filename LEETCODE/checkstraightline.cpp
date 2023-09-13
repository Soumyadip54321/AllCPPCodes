#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool checkStraightLine(vector<vector<int>>& coordinates);


int main(){
    vector<vector<int>> coordinates={{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    cout<<checkStraightLine(coordinates)<<endl;
    return 0;
}
bool checkStraightLine(vector<vector<int>>& coordinates){
    /*idea: 1. we find the slopes of each coordinate from the first one
            2. if at any instant slope differs return false else true*/
    double slope,subslopes;
    if(coordinates[1][0]==coordinates[0][0]){                       /*holds the first gradient value*/
            slope=INFINITY;
        }
    else
        slope=((coordinates[1][1]*1.0-coordinates[0][1]*1.0)/(coordinates[1][0]*1.0-coordinates[0][0]*1.0));


    for(int i=2;i<coordinates.size();i++){
        if(coordinates[i][0]==coordinates[0][0]){               /*computes subsequent slopes and compares with initial slope calculated*/
            subslopes=INFINITY;
        }
        else
            subslopes=((coordinates[i][1]*1.0-coordinates[0][1]*1.0)/(coordinates[i][0]*1.0-coordinates[0][0]*1.0));

        if(slope!=subslopes)
                return false;
    }
    return true;
}