#include <iostream>
using namespace std;

// FIND THE FIRST & LAST OCCURENCE OF AN ELEMENT IN AN ARRAY
// array = {2,2,3,3,3,3,5,1} FIND 3 // OUTPUT [2,5]

int firstOccurence(int arr[],int n,int k){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while (start <= end)
    {
        if(arr[mid] == k){
            ans = mid;
            end = mid-1;
        } else if (arr[mid] < k){
            start = mid+1;
        } else {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int lastOccurence(int arr[],int n,int k){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while (start <= end)
    {
        if(arr[mid] == k){
            ans = mid;
            start = mid+1;
        } else if (arr[mid] < k){
            start = mid+1;
        } else {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}


int main(){

  int arr[9] = {2,2,4,4,4,4,4,6,7};
  // TEST CASES
//   int arr[10] = {2,2,3,3,3,4,4,6,7,7};
//   int arr[3] = {2,2,2};
//   int arr[7] = {7,7,7,7,7,7,7};
//   int arr[1] = {8};



  cout << firstOccurence(arr,9,4) << "  " << lastOccurence(arr,9,4)<< endl;

  return 0;
}