/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    while (b){
        a %= b;
        swap(a, b);
    }
    return a;
    
    //*****************
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
//Ha Vinh Phuoc 20215455 
