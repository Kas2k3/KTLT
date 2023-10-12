/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <bits/stdc++.h>

using namespace std;

int T, t[20][2], H, N;
int a[20], sum = 0;

void TRY(int i){
	//Ham de quy thu tat ca cac gia tri cho bit tai vi tri i trong xau  
    if (i > N) { //Neu da xet den tat ca cac vi tri trong xau 
        for (int i = 1;  i <= N; ++i){
            if (sum != H) return; //Kiem tra sum, neu khac H 
            cout << a[i]; //In ra xau  
            if (i == N) cout << endl;
        }
        return;
    }
    int old_S = sum; 
    a[i] = 0;
    TRY(i+1);
    sum = old_S;
    //Luu gia tri sum hien tai vao old_S de luu trang thai truoc thay doi  

    if (sum < H) {	//Neu ta co the dat bit tai vi tri i la 1  
        a[i] = 1; //Gan bit tai vi tri i la 1  
        ++sum; //Tang sum len 
        TRY(i+1); //Goi de quy  
        sum = old_S; //Khoi phuc gia tri sum ban dau  
    }
}

int main(int argc, const char** argv) {
    cin >> T; //Nhap vao so luong bo test case  
    for (int i = 0; i < T; i++) { //Vong lap gan gia tri N va H  
        cin >> t[i][0];
        cin >> t[i][1];
    }
    for (int i = 0; i < T; i++) {
    	//Vong lap liet ke cac xau nhi phan thoa man moi test case  
        N = t[i][0];
        H = t[i][1];
        cout << endl;
        TRY(1); //Goi ham TRY de bat dau qua trinh liet ke   
    }
    return 0;
}
//Ha Vinh Phuoc 20215455
