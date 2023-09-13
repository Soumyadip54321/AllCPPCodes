#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target);

int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(matrix,45);
    return 0;
}
bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m=matrix.size(),n=matrix[0].size();
    //BETTER VERSION
    /*
    idea:
    1. since every row is sorted we apply for each row binary search and try to find target 
    */
    //TC=N*log(M);
    for(int i=0;i<m;i++){
        int low=0,high=n-1;
        while (high>=low)
        {
            int mid=(low+high)/2;
            if(matrix[i][mid]==target)
                return true;
   
            if(target>matrix[i][mid])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return false;

    //OPTIMAL VERSION
    /*
    idea:
    1. use binary search
    */

    int low=0,high=(n*m)-1;

    while (high>=low)
    {
        int mid=(low+high)/2;

        if(target==matrix[mid/n][mid%n])
            return true;

        if(target>matrix[mid/n][mid%n])
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
    //TC=O(lg(n*m))
}