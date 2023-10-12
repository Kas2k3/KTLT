/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<bits/stdc++.h>

using namespace std;

const int MAX = 10000;

int n, r;
int price[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int best, sum_price, start, des, numOfPoint;

void inputData(){ //Ham doc du lieu nguoi dung  
    cin >> n >> r; // So diem chup anh, so nguoi  
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> price[i][j];
        }
    }
}

bool check(int a, int i){
	//Ham kiem tra xem nguoi a co the di chuyen den diem i khong  
    if(visited[vt[i]]) return false; 
	//Mang boolean kiem tra diem da tham chua, neu roi thi tra ve false  
    if(price[x[a-1]][vt[i]] == 0) return false;
    //Mang luu gia tri duong di, neu bang 0 thi tra ve false  
    return true;
}

void solution(){
	//Ham kiem tra nguoi do co the di chuyen den diem ket thuc khong
    if (price[x[numOfPoint-2]][des] == 0) return;
    //Kiem tra duong di tu diem truoc diem cuoi cung den diem cuoi cung 
	//Neu bang 0 thi khong the hoan thanh lich trinh  
    best = min(best, sum_price + price[x[numOfPoint-2]][des]);
    //Neu co duong di tu diem truoc diem cuoi cung 
	//Cap nhat gia tri tot nhat  
}

void TRY(int k){
	//Ham de quy tinh kiem tra lich trinh di chuyen  
    for (int i = 1; i < numOfPoint - 1; i++){
    	//Duyet qua cac diem trong danh sach tru diem dau va cuoi  
        if (check(k, i)){
        	//Kiem tra co the di chuyen duoc khong  
            visited[vt[i]] = true;
            //Danh dau da duoc tham  
            sum_price += price[x[k-1]][vt[i]];
            //cap nhat tong chi phi  
            x[k] = vt[i];

            if (k == numOfPoint - 2) solution();
            //Neu tham het cac diem trung gian
			//Goi ham kiem tra va cap nhat gia tri tot nhat  
            else TRY(k+1);
            //Neu chua tham het diem trung gian, tiep tuc goi de quy  

            visited[vt[i]] = false;
            //Bo danh dau  
            sum_price -= price[x[k-1]][vt[i]];
            //Giam chi phi  
        }
    }
}

int main(){
    string str;
    inputData(); //Goi ham nhap du lieu  
    getline(cin,str); //Doc mot dong tu dau vao gan cho str  

    while(r > 0){
    	//Vong lap tuong ung so luong nguoi trong doan  
        best = INT_MAX; //Khoi tao gia tri tot nhat la vo cung  
        sum_price = 0; //Khoi tao tong chi phi  
        getline(cin, str);
        while (!str.empty()){
        	//Chay vong lap toi khi dong het ki tu  
            stringstream convert(str.substr(0, str.find(" ")));
            //Tao doi tuong  
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);
            //Them gia tri vao vector de luu tru danh sach diem yeu cau  

            if (str.find(" ") > str.size()) break;
            //Kiem tra neu khong con khoang trang thi thoat  
            else str.erase(0, str.find(" ") + 1);
            //Xoa phan tu chuyen doi tu str  
        }

        start = vt[0]; //Gan gia tri bat dau  
        des = vt[vt.size() - 1]; //Gan diem ket thuc  
        numOfPoint = vt.size(); //Gan gia tri so luong diem yeu cau  
        x[0] = start; x[numOfPoint-1] = des; //Diem bat dau, ket thuc  
        for(int i = 0; i < n; i++){
            visited[i] = false;
            //Khoi tao mang voi gia tri false ban dau  
        }
        TRY(1);
        //Bat dau kiem tra  

        if (best == INT_MAX) cout << "0" << endl;
        //Neu khong ton tai lich trinh hop le in ra 0  
        else cout << best << endl;
		//Neu co ton tai thi in ra gia tri tot nhat  
        vt.erase(vt.begin(), vt.end());
        //Xoa cac phan tu trong vector  
        r--;
        //Giam gia tri r de dem so nguoi da duoc xu ly  
    }
}
//Ha Vinh Phuoc 20215455  
