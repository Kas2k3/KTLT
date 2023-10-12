/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<bits/stdc++.h>

using namespace std;

//hàm sử dụng thuật toán tìm kiếm theo chiều sâu 
//adj là danh sách kề 
void dfs(vector< list<int> > adj) { 
    //sử dụng stack để lưu các đỉnh được duyệt 
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //lặp lại các câu lệnh dưới đến khi stack rỗng 
    while (!S.empty()){
        //đỉnh trên cùng là đỉnh hiện thời 
        int u = S.top();
        //kiểm tra u đã được thăm hay chưa 
        if (!visited[u]){
            //nếu chưa thăm thì đánh dấu nó 
            visited[u] = true;
            //in ra giá trị của đỉnh đó 
            cout << u <<endl;
        }
        //kiểm tra xem đỉnh hiện thời có đỉnh kề được thăm chưa 
        if (!adj[u].empty()){
            /* nếu danh sách kề khác rỗng thì lấy đỉnh kề đầu tiên
            của đỉnh hiện thời làm đỉnh kế */
            int v = adj[u].front();
            adj[u].pop_front();
            //kiểm tra đỉnh kế chưa được thăm thì đưa vào stack 
            if (!visited[v]) S.push(v);
        }
        //còn nếu danh sách kề rỗng thì loại bỏ đỉnh hiện thời đi 
        else S.pop();
    }
    
    //*****************
}

int main(){
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}
//Ha Vinh Phuoc 20215455