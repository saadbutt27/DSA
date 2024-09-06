#include <iostream>
using namespace std;

// SEARCH IN ROTATED SORTED ARRAY
// example {2,3,4,5,1} find 1 --> index:4
// example {20,30,10,15,18} find 30 --> index:1

int find_pivot(int arr[],int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while(start < end){
        if(arr[mid] >= arr[0]){
            start = mid+1;
        } else {
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return end;
}

int binary_search(int arr[],int start,int end,int key){
    int mid = start + (end-start)/2;
    while(start <= end){
        if(arr[mid] < key){
            start = mid+1;
        } else if(arr[mid] > key){
            end = mid-1;
        } else {
            return mid;
        }
        mid = start + (end-start)/2;
    }
    return -1;

}

int main(){

    int arr[] = {2,3,4,5,1};

    int pivot = find_pivot(arr,5);
    int key = 5;
    int n = 5;

    if(arr[pivot] >= key && key <= arr[n-1]){
        cout << binary_search(arr,pivot,n-1,key) << endl;
    } else {
        cout << binary_search(arr,0,pivot-1,key) << endl;
    }

  return 0;
}