#include <iostream>
using namespace std;

// Find the number of rotations in a circularly sorted array
// EXAMPLES
// Input [8, 9, 10, 2, 5, 6] --> 3
// Input [2, 5, 6, 8, 9, 10] --> 0

int pivotIndex(int arr[],int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while(start < end) {
        if(arr[0] <= arr[mid]){
           start = mid+1;
        } else {
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int main(){

  int arr[] = {8, 9, 10, 2, 5, 6};
// TEST CASES
  // int arr[] = {8, 9, 10, 30, 35, 4};
  // int arr[] = {2, 5, 6, 8, 9, 10};
  // int arr[] = {6,1,2,3,4,5};

  cout << pivotIndex(arr,6) << endl;

  return 0;
}