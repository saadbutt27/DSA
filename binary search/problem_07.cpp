#include <iostream>
using namespace std;

// BOOK ALLOCATION
// distribute books between students -> array length = no of books
// each student should get atleast one book
// each book should be allocated to a student.
// books allocation should be in contigous manner
//Example
//{10,20,30,40} -> no of student: 2  --> Output 60
//{30,20,40,70} -> no of student: 2  --> Output 90

bool isPossible(int arr[],int n,int m,int mid){
  int studentCount = 1;
  int pagesSum = 0;
  for(int i=0; i<n; i++){
    if(pagesSum+arr[i] <= mid){
      pagesSum += arr[i];
    } else {
      studentCount++;
      if(studentCount > m || arr[i] > mid){
        return false;
      }
      pagesSum = arr[i];
    }
  }
  return true;
  
}


int allocateBooks(int arr[],int n, int m){
// if number of students is greater than books
  if(m > n){
    return -1;
  }
// count total number of pages  
  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += arr[i];
  }
  int start = 0;
  int end = sum;
  int mid = start + (end-start)/2;
  int ans = -1;
  while(start <= end){
    if(isPossible(arr,n,m,mid)){
        ans = mid;
        end = mid-1;
    } else {
      start = mid+1;
    }
    mid = start + (end-start)/2;
  }
  return ans;
}

int main(){

  // int arr[] = {10,20,30,40};
  int arr[] = {30,20,40,70};
  int m = 2;

  cout << allocateBooks(arr,4,m) << endl;

  return 0;
}