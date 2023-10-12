/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<bits/stdc++.h>
using namespace std;

struct element { 
//Cau truc luu tru mot phan tu gom truong key va value  
    int key;
    int value;
};

vector<element> lst; //Khai bao vector 
void input(){
	//Ham nhap du lieu tu ban phim va luu vao vector lst  
    int tmp1, tmp2;
    while(cin >> tmp1 && cin >> tmp2){
    	//Vong lap toi khi khong doc duoc gia tri nua  
        element tmp;
        tmp.key = tmp1;
        tmp.value = tmp2;

        lst.push_back(tmp); //Them phan tu tmp vao cuoi vector lst  
    }
}

void print(){
	//Ham in ra cac phan tu trong vector lst  
    for(int i=0; i<lst.size(); i++){
        cout << lst[i].key << " " << lst[i].value << endl;
    	//In ra key va value cua phan tu thu i  
	}
}

int main(){
    input(); //Goi ham nhap du lieu  
    sort(lst.begin(),lst.end(),[] (element a, element b){
    	//Sap xep cac phan tu  
        if(a.value > b.value) return true;
        else if (a.value < b.value) return false;
        else {
            return a.key >= b.key;
        }
        //Value giam dan, neu value bang nhau thi tang dan  
    });
    print(); //Goi ham in ra phan tu duoc sap xep  

}

//Ha Vinh Phuoc 20215455  
