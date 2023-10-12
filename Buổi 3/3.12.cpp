/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;

int n, k; //So dinh va cap dinh cua do thi  
int m; //So canh cua do thi  
vector<vector<int> > vt; 
//Vector 2 chieu su dung de luu danh sach ke cua cac dinh  
int x[MAX]; //Mang luu lich trinh di chuyen  
bool visited[MAX]; //Mang danh dau cac dinh da di qua  
int cnt; //Bien dem so luong cap dinh hop le  

void inputData(){
	//
    cin >> n >> k; //Nhap vao so dinh, cap dinh  
    cin >> m; //Nhap vao so canh  
    vt.resize(n+1);//Khoi tao vector  
    for (int i = 0; i < m; i++){
    	//Doc cac canh 
        int u, v;
        cin >> u >> v;
        vt[u-1].push_back(v-1); 
        vt[v-1].push_back(u-1); 
    }

    for (int i = 0; i < n; i++){
        visited[i] = false;
        //Khoi tao mang, gan gia tri false cho cac phan tu  
    }
    cnt = 0;
}

bool check(int a, int i){
	// a la vi tri dang xet trong mang 
	// i la dinh duoc chon de dat tai a   
    if (a == 0) return true;
    //Neu a bang 0 thi khong can kiem tra va tra ve true  
    if (visited[i]) return false;
	//Neu dinh i da duoc tham truoc do thi tra ve false  
    int index = 0;
    for (int j = 0; j < vt[x[a-1]].size(); j++){
        if (i == vt[x[a-1]][j]) index++;
    }

    if (index == 0) return false;
    //Neu khong co dinh i ke voi dinh truoc do, tra ve false  
    return true;
    //Tra ve true neu qua cac buoc kiem tra tren  
}

void solution(){
	//Kiem tra giai phap hien tai la hop ly khong 
    cnt++;
    //Tang bien cnt len de dem so luong giai phap hop le  
}

void TRY(int a){
    for (int i = 0; i < n; i++){
    	//Duyet qua tat ca cac dinh trong do thi  
        if (check(a, i)){
        	//Neu dinh hien tai co the chon  
            visited[i] = true;
            //Danh dau dinh da duoc chon  
            x[a] = i;

            if(a == k) solution();
            //Neu chon du so luong dinh thi goi ham solution  
            else TRY(a+1);
            //Neu chua du thi tiep tuc goi de quy  

            visited[i] = false;
            //Bo danh dau dinh hien tai  
        }
    }
}

int main(int argc, const char** argv) {
    inputData(); //Goi ham nhap du lieu  
    TRY(0); //Bat dau tim cac ket qua  
    cout << cnt/2; 
	//In ra ket qua cuoi cung, chia 2 vi moi cap dinh dem 2 lan  
}
//Ha Vinh Phuoc 20215455  
