/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    float n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while (n--){
        float a;
        cin >> a;
        if (7 <= a && a < 8.5) ++B;
        else if (5.5 <= a && a < 7) ++C;
        else if (8.5 <= a) ++A;
        else if (4 <= a && a < 5.5) ++D;
        else if (a < 4) ++F;
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}


