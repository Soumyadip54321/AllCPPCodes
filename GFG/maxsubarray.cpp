
using namespace std;


int maxLen(int arr[], int N)
{
        // Your code here

        int ans=INT_MIN,sum=0;
        unordered_map<int,int> position;        //form:(sum,index)

        position[sum]=-1;     //cause we start with no 0s and 1s at first hence index set to -1

        for(int i=0;i<N;i++){
            if(arr[i]==0)
                sum-=1;
            else
                sum+=arr[i];

            if(position[sum])
                ans=max(ans,i-position[sum]);
            else
                position[sum]=i;
        }
        return ans;
}
int main(int argc, char const *argv[]) {
  /* code */
  int arr[]={0 1 1 1 0 0 1 0 1 0 1 0 1 0 0 1 1 0 0 1 0 0 0 1 1 1 0 0 1};
  cout <<maxLen(arr,29)<<endl;
  return 0;
}
