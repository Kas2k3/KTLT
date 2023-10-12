/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */
#include <iostream>
using namespace std;

//*****************
/* YOUR CODE HERE Ha Vinh Phuoc 20215455 */

template <class T> T arr_sum(T a[], int m,T b[], int n){
    T c = 0; 
    for(int i = 0; i < m; i++){
        c += a[i];
    }
    for(int i = 0; i < n; i++){
        c += b[i];
    }
    return c;
}

//*****************

int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
