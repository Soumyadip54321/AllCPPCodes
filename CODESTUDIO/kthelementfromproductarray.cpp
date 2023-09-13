#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int kthSmallest(vector<int> &arr, int k);

const int n=1e5;
int hsh[n];
int total[n];

int main(){
    vector<int> arr={-54, 30, 37, -70, 40, -37, 22, -15, 87};
    cout<<kthSmallest(arr,32)<<endl;
    return 0;
}
int kthSmallest(vector<int> &arr, int k){
    // int pos=k;
    // sort(arr.begin(),arr.end());

    // for(int i=0;i<arr.size();i++){
    //     hsh[i]=arr.size()-i-1;
    //     cout<<arr[i]<<",";
    // }

    // total[0]=hsh[0];
    // for(int i=1;i<arr.size();i++){
    //     total[i]=total[i-1]+hsh[i];
    // }

    // if(k>total[arr.size()-1])
    //     return -1;
    // int stidx;

    // for(int i=0;i<arr.size();i++){
    //     if(k<=total[i]){
    //         stidx=i;
    //         break;
    //     }
    // }
    // cout<<arr[stidx]<<endl;
    // if(arr[stidx]==0)
    //     return 0;

    // // if(arr[stidx]<0){
    // //     int j=arr.size()-1;
    // //     pos--;
    // //     while (pos)
    // //     {
    // //         j--;
    // //         pos--;
    // //     }
    // //     cout<<arr[j]<<endl;
    // //     return arr[stidx]*arr[j];
    // // }

    // // int j=stidx+1;
    // // pos--;
    // // while (pos)
    // // {
    // //     j++;
    // //     pos--;
    // // }
    // if(stidx==0){
    //     return arr[stidx]*arr[k];
    // }

    // k-=total[stidx-1];
    // return arr[stidx]*arr[stidx+k];
    
    // //naive approach
    vector<int> products;
	for(int i=0;i<arr.size();i++){
		for(int j=i+1;j<arr.size();j++){
			products.push_back(arr[i]*arr[j]);
		}
	}
    sort(products.begin(),products.end());

    if(k>products.size())
        return -1;
    return products[k-1];
    return 0;
}