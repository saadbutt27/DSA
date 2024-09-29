#include <iostream>
using namespace std;

// FIND PIVOT INDEX
// Example {7,9,1,2,3} --> index:2
// Example {10,12,15,18,5,7} --> index:4
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

    int arr[] = {7,9,1,2,3}; // --> 2
    // TEST CASES
    // int arr[6] = {10,12,15,18,5,7}; --> 4
    // int arr[6] = {10,12,15,18,20,1}; --> 5
    cout << pivotIndex(arr,6) << endl;

  return 0;
}