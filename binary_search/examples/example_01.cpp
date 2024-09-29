#include <iostream>
using namespace std;

// FIND THE INDEX OF A KEY PRESENT IN AN ARRAY THROUGH BINARY SEARCH

int binary_search(int arr[],int n,int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while (start<=end){
        if(arr[mid] == key){
            return mid;
        } else if(arr[mid] < key){
            start = mid+1;
        } else {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int recursive(int arr[],int l,int h, int key){
    if(l <= h){
        int mid = l + (h-l)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            return recursive(arr,0,mid-1,key);
        }
        return recursive(arr,mid+1,h,key);
    }
    return -1;
}

int main(){

    int even[] = {2,4,5,8,10,15,20,22};

    cout << binary_search(even,8,22) << endl;
    cout << recursive(even,0,8-1,5);

  return 0;
}