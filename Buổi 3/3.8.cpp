/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <bits/stdc++.h>
using namespace std;

struct state{ 
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
    //Khoi tao gia tri constructor 
};

int main() {
    int n, M;
    cin >> n >> M; // Nhap vao gia tri n va M  
    int m[n+1]; //Mang co kich thuoc n+1
    for (int i = 1; i <= n; ++i) cin >> m[i];
    //Vong lap nhap gia tri cho cac phan tu 
    int x[n+1]; //Mang luu tru cac gia tri danh dau 
    stack<state> s; //Stack luu tru cac trang thai khi backtracking
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1));
    //Day mot trang thai khoi tao vao stack
    while (!s.empty()){
        state &top = s.top();
        //Duyet qua cac trang thai trong stack va thuc hien backtracking
        if (top.i > n){ //Neu vi tri cu vuot qua n
            if (sum == M){ //Kiem tra neu sum bang M khong?
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                    //Neu co thi in ra bieu dien 
                }
                cout << "=" << M;
                exit(0);
                //Thoat khoi
            }
            s.pop();
            //Neu khong tim thay ket qua thi lap lai qua trinh backtracking
            continue;
        }
        
        //# Khu de quy  
        //back track  
        //*****************
        /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
        
        if (top.j > -1) {
        	//Kiem tra xem da thuc hien chon gia chi cho top.i chua?
        	sum -= m[top.i] * x[top.i];
        	//Neu chon roi thi tru tong sum di mot gia tri tuong ung
		} 
		//#every subtrees are visited
		if(top.j > 1) {
			//Kiem tra xem cac nhanh con da duoc duyet hay chua
			s.pop();
			//Neu duyet roi thi loai bo trang thai hien tai khoi stack
			continue;
			//Chuyen den trang thai tiep theo
		}
		x[top.i] = top.j;
		sum += m[top.i] * x[top.i];
		//Cap nhat tong sum
		s.push(state(top.i + 1, -1));
		//Day trang thai moi vao stack
		++top.j;
		//Tang gia tri top.j, chuan bi cho lan duyet ke tiep
        
        //*****************
    }
    cout << -1;

    return 0;
}
//Ha Vinh Phuoc 20215455  
