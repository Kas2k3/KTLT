/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 210;

int N, K1, K2, cnt = 0;
int a[MAX], sum = 0, dau = -1;

void TRY(int i){ //Ham thu tat ca cac kha nang cho ngay thu i 
    if (i > N) { //Neu xu ly het cac ngay thi goi vong lap
        for (int i = 1;  i<= N; ++i){
            if (sum < K1 && sum > 0) return;
            cout << a[i];
            //In ra lich lam viec
        }
        cnt++; //Tang bien dem
        cout << endl;
        return;
    }
    if (dau == -1) {
    	//Kiem tra xu ly ngay dau tien chua
        a[i] = 0;
        dau = 0;
        TRY(i + 1);
        //Thu truong hop ngay dau tien la 0, goi de quy

        a[i] = 1;
        dau = 1;
        sum = 1;
        TRY(i + 1);
        //Thu voi truong hop ngay dau tien la 1, goi de quy
        exit(0);
    }

    int old_S = sum; //Luu gia tri sum vao old_S
    int old_D = dau; //Luu gia tri dau vao bien old_D

    if (old_D == 0) {
    	//Truong hop xu ly khi ngay truoc do la ngay nghi
        a[i] = 1;
        dau = 1;
        sum = 1;
        TRY(i + 1);
        //Thu voi ngay thu i la 1, goi de quy
        sum = old_S; //Cap nhat 'dau'
        dau = old_D; //Cap nhat 'sum' thanh 1 de dam bao 
    }else{
    	//Xay ra khi nngay truoc do la ngay lam viec
        if (old_S < K2) { //Neu tong so ngay lam viec < K2
            if (old_S >= K1) { 
			//Kiem tra xem co du ngay lam trong chuoi ngay lien tuc
                a[i] = 0;
                dau = 0;
                sum = 0;
                TRY (i + 1);
                sum = old_S;
                dau = old_D;
            }

            a[i] = 1;
            dau = 1;
            ++sum;
            TRY(i + 1);
            sum = old_S;
            dau = old_D;
        }else {
        	//Xu ly khi tong ngay lam viec khong nho hon K2
            a[i] = 0;
            dau = 0;
            sum = 0;
            TRY (i + 1);
            sum = old_S;
            dau = old_D;
        }
    }
}

int main(int argc, const char** argv) {
    cin >> N >> K1 >> K2;
    TRY(1);
    cout << cnt;
    return 0;
}
//Ha Vinh Phuoc 20215455 
