#include <iostream>
using namespace std;

// FIND SQUARE ROOT OF A NUMBER
// 💡 if you want to store square = m*m use data type "long long int" //

int square_root(int n){
    int start = 0;
    int end = n;
   int ans = -1;
   while(start <= end){
    int mid = start + (end-start)/2;
    int square = mid*mid;

    if(square == n){
        return mid;
    } else if (square < n){
        ans = mid;
        start = mid+1;
    } else {
        end = mid-1;
    }
    
   }
   return ans;
}

double morePrecise(int n,int precision,int temp){
    float factor = 1;
    double ans = temp;
    for(int i=0; i<precision; i++){
        factor = factor/10;
        cout << temp << endl;
        for(double j=ans; (j*j)<n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){

  int temp =  square_root(37);

  cout << morePrecise(37,3,temp) << endl;

  return 0;
}