/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;
using Point = pair<double, double>;

//hàm tính diện tích dựa trên các điểm truyền vào 
double area(Point a, Point b, Point c){
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //tích vô hướng của vector AB và vector AC 
    double x = (b.first - a.first) * (c.second - a.second);
    //tích vô hướng của vector AC và vector AB 
    double y = (c.first - a.first) * (b.second - a.second);
    //trả về trị tuyệt đối để lấy độ dài
    return fabs(x-y)/2;
    
    //*****************
}

int main() {
    //in ra kết quả với 2 chữ số thập phân sau dấu phẩy 
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
//Ha Vinh Phuoc 20215455