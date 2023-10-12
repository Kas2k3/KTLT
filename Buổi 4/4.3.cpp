/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
using Vector = tuple<double, double, double>;

//hàm tính tích có hướng của 2 vector trong kgian 3 chiều 
Vector cross_product(Vector a, Vector b){
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //tính toán phần x của vector c 
    double x = get<1>(a)*get<2>(b) - get<2>(a)*get<1>(b);
    //tính toán phần y của vector c
    double y = get<2>(a)*get<0>(b) - get<0>(a)*get<2>(b);
    //tính toán phần z của vector c 
    double z = get<0>(a)*get<1>(b) - get<1>(a)*get<0>(b);
    Vector c = {x, y, z};
    return c;
    
    //*****************
}

int main() {
    cout << setprecision(2) << fixed;
    Vector a {2.0, 4.0, -0.5};
    Vector b {1.5, -2.0, 3.3};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}
//Ha Vinh Phuoc 20215455 