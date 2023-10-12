/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<bits/stdc++.h>

using namespace std;

//định nghĩa giá trị 
struct data {
    int ai; 
    int ki; 

    data(int ai, int ki){
        this->ai = ai; 
        this->ki = ki;
    }
};

//định nghĩa toán tử so sánh cho cặp giá trị data
struct comp{
    bool operator() (data a, data b){
        int ra, rb;

        //tính toán giá trị đầu ra cho đối tượng a
        if (a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        //tính toán giá trị đầu ra cho đối tượng b
        if (b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb;
    }
};

//số lượng đoạn tường n, số lính s, số địch bị tiêu diệt và tổng địch
int n, s, kill_enemy, total_enemy;
priority_queue<data, vector<data>, comp> Q;

//hàm nhận dữ liều đầu vào từ người dùng
void inputData(){
    cin >> n >> s;
    kill_enemy = 0;
    total_enemy = 0;
    for (int i=0; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        total_enemy += tmp1;
        Q.push(data(tmp1, tmp2));
    }
}

//hàm thực hiện việc phân bố lính đứng sao cho tổng số lính s
//tổng số địch lọt vào lâu đài là nhỏ nhất
void solve(){
    //vòng lặp kiểm tra đảm bảo hàng đợi ưu tiên không trống
    //đảm bảo còn lính để phân bổ
    while (!Q.empty() && s>0){
        data inf = Q.top(); 
        Q.pop();

        if (inf.ai <= inf.ki) kill_enemy += inf.ai;
        else {
            int nenemy = inf.ai - inf.ki;
            Q.push(data(nenemy, inf.ki));
            kill_enemy += inf.ki;
        }

        s -= 1;
    }
}

//hàm trả về số địch còn lại 
int calc_enemy(){
    return total_enemy - kill_enemy;
}

int main(){
    inputData();
    solve();
    cout << calc_enemy();
    return 0;
}