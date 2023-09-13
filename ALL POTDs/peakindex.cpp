#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int> &arr);

int main()
{
    vector<int> arr = {3, 5, 3, 2, 0};
    cout << peakIndexInMountainArray(arr);
    return 0;
}
int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (high - low > 1)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            low = mid;
        else
            high = mid;
    }
    if (low != high)
    {
        if (arr[low] > arr[high])
            return low;
        else if (arr[low] < arr[high])
            return high;
    }
    return high;
}