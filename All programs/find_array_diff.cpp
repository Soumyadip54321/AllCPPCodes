#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);
const int N=1e3+10;
int element1[N];
int element2[N];


int main(){
    vector<int> num1={-99},num2={-63};
    vector<vector<int>> different_elements;
    different_elements=findDifference(num1,num2);

    for(int i=0;i<different_elements.size();i++){
        cout<<"{";
        for(auto item:different_elements[i])
            cout<<item<<" ";
        cout<<"}"<<endl;
    }

    return 0;
}
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2){
    vector<vector<int>> diff_ele;
    int size1,size2,minimum1=0,minimum2=0;
    if(*min_element(nums1.begin(),nums1.end())<0)
        minimum1=*min_element(nums1.begin(),nums1.end());
    
    if(*min_element(nums2.begin(),nums2.end())<0)
        minimum2=*min_element(nums2.begin(),nums2.end());

    int maximum1=*max_element(nums1.begin(),nums1.end());
    int maximum2=*max_element(nums2.begin(),nums2.end());

    cout<<maximum1<<" "<<minimum1<<endl;
    cout<<maximum2<<" "<<minimum2<<endl;

    if(minimum1<0)
        size1=maximum1-minimum1;        //here index 0=> minimum element
    else
        size1=maximum1;
    
    if(minimum2<0)
        size2=maximum2-minimum2;        //here index 0=> minimum element
    else
        size2=maximum2;
    
    for(auto item:nums1)
        element1[item-minimum1]=1;
    
    for(auto item:nums2)
        element2[item-minimum2]=1;

    int i=0,j=0;
    while(i<nums1.size()){
        if(nums1[i]-minimum2<=size2 && nums1[i]-minimum2>=0){
            if(element1[nums1[i]-minimum1]==1 && element2[nums1[i]-minimum2]==1){
                element2[nums1[i]-minimum2]=0;
                element1[nums1[i]-minimum1]=0;
            }
        }
        i++;
    }

    vector<int> list1_unique,list2_unique;

    for(int i=0;i<=size1;i++){
        if(element1[i]==1){
            list1_unique.push_back(i+minimum1);
        }
    }

    for(int i=0;i<=size2;i++){
        if(element2[i]==1){
            list2_unique.push_back(i+minimum2);
        }
    }
    diff_ele.push_back(list1_unique);
    diff_ele.push_back(list2_unique);
    return diff_ele;
}