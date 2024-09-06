#include <iostream>
using namespace std;

// PEAK INDEX IN MOUNTAIN ARRAY
//  Array will bill be mountain
// Example // {0,2,1,0} // {3,4,5,1} // {0,10,5,2} // {0,1,0} 

int peakInaMountain(int arr[],int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while(start < end){
        if(arr[mid] < arr[mid+1]){
            start = mid+1;
        } else if(arr[mid] < arr[mid-1]) {
            end = mid-1;
        } else {
            return mid;
        }
        mid = start + (end-start)/2;
    }
    return mid;
}

int main(){

    int arr[7] = {0,10,50,60,70,90,0};

    cout << peakInaMountain(arr,7) << endl;

  return 0;
}