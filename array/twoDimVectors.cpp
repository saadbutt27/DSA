#include <iostream>
#include <vector>
using namespace std;

bool searchInRow(vector<vector<int>> matrix, int target, int row) {
    int n = matrix[0].size();
    int st = 0, end = n-1;
    // TC = O(log(n))
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (target == matrix[row][mid]) {
            return true;
        } else if (target > matrix[row][mid]) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Each row is sorted in non-decreasing order.
    // The first integer of each row is grater than the last integer of the previous row.

    // BRUTE FORCE APPROACH - O(n * m)
    // Apply linear search     

    // OPTIMIZED APPROACH - O(log(m) + log(n)) = O(log(m * n))  
    int m = matrix.size(), n = matrix[0].size();
    int startRow = 0, endRow = m-1;
    // TC = O(log(m))
    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2;
        if (target >= matrix[midRow][0] && target <= matrix[midRow][n-1]) {
            return searchInRow(matrix, target, midRow);
        } else if (target >= matrix[midRow][n-1]) {
            startRow = midRow + 1;
        } else {
            endRow = midRow - 1;
        }
    } 

    return false;
}

bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    // TC = O(n + m)
    int m = matrix.size(), n = matrix[0].size();

    int r = 0, c = n-1;
    while (r < m && c >= 0) {
        if (target == matrix[r][c]) {
            return true;
        } else if (target >= matrix[r][c]) {
            r++;
        } else {
            c--;
        }
    }

    return false;   
}

int main() {
    // vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    // rows => mat.size();
    // cols => mat[i].size();
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[i].size(); j++) {
            cout << mat[i][j] << " "; 
        }
        cout << endl;
    }

    // cout << searchMatrix(mat, 34+1) << endl;
    cout << searchMatrix2(mat, 5) << endl;
    return 0;
}