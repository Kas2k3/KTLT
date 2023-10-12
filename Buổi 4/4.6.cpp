/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<bits/stdc++.h>

using namespace std;

//hàm sử dụng thuật toán tìm kiếm theo chiều rộng 
//adj là danh sách kề 
void bfs(vector< list<int> > adj) {
    //khởi tạo hàng đợi để lưu đỉnh cần duyệt 
    queue<int> Q;
    //vector đánh dấu đỉnh đã được thăm 
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //lặp đến khi hàng đợi rỗng 
    while (!Q.empty()) {
        //lấy đỉnh đầu tiên làm đỉnh hiện thời
        int u=Q.front();
        //nếu nó đã chưa thăm thì đánh dấu nó đã được thăm 
        if (!visited[u]){
            visited[u] = true;
            cout<< u << endl;
        }
        //nếu danh sách kề không rỗng 
        if (!adj[u].empty()){
            //lấy đỉnh kề đầu tiên của đỉnh hiện thời làm đỉnh kế 
            int v = adj[u].front(); 
            //loại bỏ đỉnh kề đầu tiên khỏi danh sách kề  
            adj[u].pop_front();
            //nếu đỉnh kề chưa thăm thì thêm nó vào hàng đợi 
            if (!visited[v]) Q.push(v);
        }
        //nếu danh sách kề rỗng thì loại bỏ định hiện thời khỏi hàng đợi 
        else Q.pop();
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
    bfs(adj);
}
//Ha Vinh Phuoc 20215455