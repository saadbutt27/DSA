#include <iostream>
using namespace std;

// void travers2DArray(int arr[][], int rows, int columns) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < columns; j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// bool linearSearch(int mat[][3], int rows, int cols, int key) {
//     for (int i=0; i<rows; i++) {
//         for (int j=0; j<cols; j++) {
//             if (mat[i][j] == key) return true;
//         }
//     }
//     return false;
// }
// pair<int, int> linearSearchPair(int mat[][3], int rows, int cols, int key) {
//     pair<int, int> cellPair = {-1, -1};
//     for (int i=0; i<rows; i++) {
//         for (int j=0; j<cols; j++) {
//             if (mat[i][j] == key) {
//                 cellPair.first = i;
//                 cellPair.second = j;
//                 return cellPair;
//             };
//         }
//     }
//     return cellPair;
// }

// int getMaxRowSum(int mat[][3], int rows, int cols) {
//     int maxRowSum = INT_MIN;
//     for (int i=0; i<rows; i++) {
//         int rowSumI = 0;
//         for (int j=0; j<cols; j++) {
//             rowSumI += mat[i][j];
//         }
//         maxRowSum = max(maxRowSum, rowSumI);
//     }
//     return maxRowSum;
// }
// int getMaxColSum(int mat[][3], int rows, int cols) {
//     int maxColSum = INT_MIN;
//     for (int i=0; i<cols; i++) {
//         int colSumI = 0;
//         for (int j=0; j<rows; j++) {
//             colSumI += mat[j][i];
//         }
//         maxColSum = max(maxColSum, colSumI);
//     }
//     return maxColSum;
// }

int diagonalSum(int mat[][4], int n) {
    // Diagonal is a straight line joining two opposity ends of a square/rectangle 
    // Primary diagonal is from top-left to bottom-right 
    // Secondary diagonal is from top-right to bottom-left 
    // Diagonal sum is the sum of primary and secondary diagonals.
        // DS = PD + SD
    // For a matrix of odd size(n, n means a matrix of order n*n), diagonal sum is the sum of primary and secondary diagonals, subtracting the common elements.
        // DS = PD + SD - common_elements

    int sum = 0;
    // for (int i=0; i<n; i++) { //O (n*n)
    //     for (int j=0; j<n; j++) {
    //         if (i == j) {
    //             pdSum += mat[i][j];
    //         } else if (j == n-i-1) {
    //             sdSum += mat[i][j];
    //         }
    //     }
    // }

    // We don't need the nested j loop, because both PD and SD can be determined by i.
    // We can use the fact that, for PD j == i, we can target those elements with mat[i][i]
    // We can use the fact that, for SD j == n-i-1, we can target those elements with mat[i][n-i-1]
    for (int i=0; i<n; i++) { //O (n)
        sum += mat[i][i];
        if (i != n-i-1) {
            sum += mat[i][n-i-1];
        }
    }

    return sum;

}

int main() {
    // 2D Array
    int rows = 4; 
    int columns = 3; 
    int n = 4;
    int matrix[n][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    // Accessing a particular element
    // cout << matrix[2][1] << endl;

    // // Updating an element
    // matrix[2][1] = 0;
    // cout << matrix[2][1] << endl;

    // Loops on 2D Array
    // Iput
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < columns; j++) {
    //         cin >> matrix[i][j];
    //     }
    // }

    // Output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 2D Array in Memory
    // 1. Row major: The elements in 2d array will be stored row wise in memory.
    // 1. Column major: The elements in 2d array will be stored column wise in memory.

    // cout << linearSearch(matrix, rows, columns, 8) << endl;
    // pair<int, int> cellPair1 = linearSearchPair(matrix, rows, columns, 8);
    // cout << cellPair1.first << " " << cellPair1.second << endl;
    // cout << linearSearch(matrix, rows, columns, 20) << endl;
    // pair<int, int> cellPair2 = linearSearchPair(matrix, rows, columns, 20);
    // cout << cellPair2.first << " " << cellPair2.second << endl;

    // cout << getMaxRowSum(matrix, rows, columns) << endl;
    // cout << getMaxColSum(matrix, rows, columns) << endl;

    cout << diagonalSum(matrix, n) << endl;
    return 0;
}