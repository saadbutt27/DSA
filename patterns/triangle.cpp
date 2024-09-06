#include <iostream>
using namespace std;

int main()
{
    // Triangle patterns
    int n = 4;

    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            cout << (i+1) << " ";
        }
        cout << endl;
    }

    cout << endl;
    char ch = 'A';
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }

    cout << endl;

    for (int i=0; i<n; i++) {
        // int num = 1;
        for (int j=1; j<=i+1; j++) {
            cout << j << " ";
            // num++;
        }
        cout << endl;
    }

    cout << endl;
    // Reverse triangle
    for (int i=0; i<n; i++) {
        for (int j=i+1; j>0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
    for (int i=0; i<n; i++) {
        ch = 'A' + i;
        for (int j=i+1; j>0; j--) {
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }

    cout << endl;
    // Floyd's triangle
    int num = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    cout << endl;
    // Floyd's triangle
    ch = 'A';
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }

    cout << endl;
    // Inverted triangle
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            cout << "  ";
        }
        for (int j=0; j<n-i; j++) {
            cout << (i+1) << " ";
        }
        cout << endl;
    }

    cout << endl;
    // Inverted triangle
    ch = 'A';
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            cout << "  ";
        }
        for (int j=0; j<n-i; j++) {
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
    
    cout << endl;
    // Inverted accurate triangle
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            cout << " ";
        }
        for (int j=0; j<n-i; j++) {
            cout << (i+1) << " ";
        }
        cout << endl;
    }

    cout << endl;
    // Pyramid 
    // DIvide the pattern into two parts, meand pyramid into two parts
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            cout << "  ";
        }
        for (int j=1; j<=i+1; j++) {
            cout << j << " ";
        }
        for (int j=i; j>0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
    // Hollow diamond 
    // Divide the pattern into two parts, meand pyramid into two parts
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            cout << "  ";
        }
        cout << "* ";
        if (i != 0) {
            for (int j=0; j<2*i-1; j++) {
                cout << "  ";
            }
            cout << "* ";
        }
        cout << endl;
    }
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<i+1; j++) {
            cout << "  ";
        }
        cout << "* ";
        if (i != n-2) {
            for (int j=0; j<2*(n-i)-5; j++) {
                cout << "  ";
            }
            cout << "* ";
        }
        cout << endl;
    }

    cout << endl;
    // Butterfly
    n=5;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            cout << "* ";
        }
        for (int j=0; j<n-i-1; j++) {
            cout << "  ";
        }
        for (int j=n-i-1; j>0; j--) {
            cout << "  ";
        }
        for (int j=i+1; j>0; j--) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<i+1; j++) {
            cout << "* ";
        }
        for (int j=0; j<n-i-1; j++) {
            cout << "  ";
        }
        for (int j=n-i-1; j>0; j--) {
            cout << "  ";
        }
        for (int j=i+1; j>0; j--) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}