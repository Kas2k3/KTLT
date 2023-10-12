/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<bits/stdc++.h>

using namespace std;
int n;

struct Matrix{ //Cau truc de luu tru mang va ham  
    int n,m; //Khai bao gia tri hang va cot cua mang  
    int** matrix; //Khai bao bien con tro  
    Matrix(int r, int c){
        n = r; //Gan gia tri hang  
        m = c; //Gan gia tri cot  
        matrix = new int*[n]; 
		//Cap phat mang dong chua con tro voi so hang n  
        for (int i = 0; i < m; i++){
            matrix[i] = new int[m];
		//Cap phat mang dong chua con tro voi so cot m  
        } 
    }
    void inputMatrix(){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> matrix[i][j];
        //Nhap gia tri cho cac phan tu trong mang  
            }
        }
    }
    void printMatrix(){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << matrix[i][j] << ' ';
        //In ra man hinh gia tri cac phan tu da nhap  
            }
            cout << endl;
        }
    }
    void add(Matrix* b){ //Ham tinh tong 2 ma tran  
        if(n != b->n || m != b->m){
            cout << "Khong cung kich thuoc ma tran" << endl;
            return;
        //Neu 2 ma tran khac kich thuoc thi khong cong duoc ma tran  
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << matrix[i][j] + b->matrix[i][j] << " ";
        //Tong cac phan tu tuong ung cua 2 ma tran duoc luu vao bien count 
            }
            cout << endl;
        }
    }
    void multiply(Matrix* b){ //Ham tinh tich 2 ma tran  
        if (m != b->n){
            cout << "Khong hop le" << endl;
            return;
        /*Neu so cot cua ma tran nay khac so hang cua ma tran kia
		thi ta khong thuc hien nhan ma tran */ 
        }
        Matrix* c = new Matrix(n,b->m); //Cap phat dong bo nho cho con tro  
        for (int i = 0; i < n; i++){
            for (int j = 0; j < b->m; j++){
                c->matrix[i][j] = 0; //Khoi tao cac phan tu bang 0  
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int a = 0; a < b->m; a++){
                    c->matrix[i][a] += matrix[i][j]*b->matrix[j][a];
                }
            }
        }
        //Dam bao day du dieu kien, thuc hien nhan ma tran  
        c->printMatrix(); //Goi ham in ket qua  
        delete c; //Giai phong bo nho  
    }
};

int main(){
    cout << "Ha Vinh Phuoc - K66 DHBKHN" << endl;
    cin >> n; //Nhap vao  ma tran cap n  
    Matrix* a = new Matrix(n, n); //Cap phat bo nho dong  
    a->inputMatrix(); //Truy nhap den ham nhap gia tri
    Matrix* b = new Matrix(n, n); //Cap phat bo nho dong  
    b->inputMatrix(); //Truy nhap den ham ham nhap gia tri  
    cout << "Ket qua la: " << endl; 
    a->add(b); //Truy nhap den ham tinh tong 2 ma tran  
    a->multiply(b); //Truy nhap den ham tinh tich 2 ma tran  
    delete a; //Giai phong bo nho  
    delete b; //Giai phong bo nho  
    return 0;
}
//Ha Vinh Phuoc 20215455 
