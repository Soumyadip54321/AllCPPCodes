#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int maxLength(int n, vector<int> &arr);
vector <int> partitionLabels(string & s);

int main(){
    vector<int> arr={10, 11, 12, 15, 14, 13, 16, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 210, 212, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 230, 242, 244, 246, 248, 250, 252, 254, 256, 258, 260, 262, 264, 266, 268, 270, 272, 274, 276, 278, 280, 282, 284, 286, 288, 290, 292, 294, 296, 298, 300, 302, 304, 306, 308, 310, 312, 314, 316, 318, 320, 322, 324, 326, 328, 330, 332, 334, 336, 338, 340, 342, 344, 346, 348, 350, 352, 354, 356, 358, 360, 362, 364, 366, 368, 370, 372, 374, 376, 378, 380, 382, 384, 386, 388, 390, 392, 394, 396, 398, 400, 402, 404, 406, 408, 410, 412, 414, 416, 418, 420, 422, 424, 426, 428, 430, 432, 434, 436, 438, 440, 442, 444, 446, 448, 450, 452, 454, 456, 458, 460, 462}; 
    cout<<maxLength(227,arr);
    return 0;
}
int maxLength(int n, vector<int> &arr){
    /*
    idea:
    1. we sort arr to check if it has a constant common diff b/w elements
    2. If they form an A.P we return size of array as the array forms a continuous subarray
    3. else we length of largest subarray and return
    */
    if(n==1)
        return 1;

   vector<int> arrdup=arr;
   bool isordered=true;
   int i=0,maxsublength=1,length=1;

   sort(arrdup.begin(),arrdup.end());
   

   while (i<n-1)
   {
        if(not(arrdup[i+1]-arrdup[i]==1)){
            isordered=false;
            break;
        }
        i++;
   }

    if(isordered)
        return n;

    int j=1,startpoint;
    i=0;
    startpoint=i;

    while (i<n-1)
    {
        if(abs(arr[i+1]-arr[i])==1){
            length++;
            maxsublength=max(maxsublength,length);
            i++;
        }
        else{
            length=1;
            i=startpoint+1;
            startpoint=i;
        }
    }
    //cout<<maxsublength<<endl;
    return maxsublength;
}