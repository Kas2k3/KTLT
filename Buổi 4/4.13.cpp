/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<bits/stdc++.h>

using namespace std;

int n;
string str;
int cnt = 0, res = 0;
map<int, int> m;

void inputData(){
    cin >> str; // Nhập chuỗi str từ người dùng
    n = str.length(); // Độ dài của chuỗi str
}

// Hàm tính tổng các số từ 1 đến b
int calc(int b){
    int foo = 0;
    for (int i = 1; i < b; i++){
        foo += i;
    }
    return foo;
}

void solve(){
    int slg0 = 0, slg1 = 0; // Số lượng số 0 và số 1
    map<int, int>::iterator it;

    for (int i=0; i<n; i++){
        if (str[i] == '0') slg0++; // Nếu ký tự là '0', tăng số lượng số 0
        else slg1++; // Ngược lại, tăng số lượng số 1

        int tmp = slg1 - slg0; // Độ chênh lệch số lượng số 0 và số 1
        it = m.find(tmp); // Tìm kiếm độ chênh lệch trong map
        if (it != m.end()){ // Nếu độ chênh lệch đã tồn tại trong map
            it->second += 1; // Tăng số lượng cặp số 0 và số 1 có cùng độ chênh lệch
        }else{
            m.insert({tmp, 1}); // Thêm độ chênh lệch vào map với số lượng là 1
        }
    }

    it = m.begin();
    while (it != m.end()){
        res += calc(it->second); // Tính tổng các cặp có cùng độ chênh lệch
        if (it->first == 0) res += it->second; // Nếu độ chênh lệch là 0, thì cộng thêm số lượng độ chênh lệch này
        it++;
    }
}

int main(){
    inputData();
    solve();
    cout << res; // In ra kết quả
    return 0;
}
//Ha Vinh Phuoc 20215455
