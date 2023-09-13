#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

void addelement(vector<int>);

class KthLargest {
    int K;
    vector<int> elements;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        elements=nums;
        sort(elements.begin(),elements.end(),greater<int>());      // T(n)=O(nlogn)
    }
    int add(int val) {
        int found=0;       //sorting to be done in O(n) here and not in O(nlogn)
        if(not(elements.empty())){
            for(int i=0;i<elements.size();i++){
                if(elements[i]<=val){
                    elements.insert(elements.begin()+i,val);
                    found=1;
                    break;
                }
            }
            if(found==0)
                elements.push_back(val);
        }
        else
            elements.push_back(val);
        return elements[K-1];
    }

    void display(){
        for(auto val:elements)
            cout<<val<<" ";
        cout<<endl;
    }
};

//T(n)=O(nlogn);

int main(){
    int n=3;
    vector<int> nums={4,5,8,2};
    KthLargest kthLargest(n, nums);
    //kthLargest.display();
    cout<<kthLargest.add(3)<<endl;
    cout<<kthLargest.add(5)<<endl;   // return 5
    cout<<kthLargest.add(10)<<endl;  // return 5
    cout<<kthLargest.add(9)<<endl;   // return 8
    cout<<kthLargest.add(4)<<endl;
    return 0;
}