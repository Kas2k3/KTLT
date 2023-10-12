/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */


#include <iostream>
#include <queue>
#include <climits>

using namespace std;

//cấu trúc tạo hàm so sánh tùy chỉnh 
struct comp{
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

//hàm nhận mảng 2 chiều là đồ thị trọng số, sử dụng dijkstra 
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */

    //cấu trúc triển khai hàng đợi ưu tiên dùng lưu trữ khoảng cách
    priority_queue<pair<int, int>, vector< pair<int, int> >, comp> q;
    
    //vector lưu trữ khoảng cách đỉnh xuất phát đến các đỉnh còn lại 
    vector<int> dist(adj.size());
    int dist_size = dist.size();
    //các khoảng cách bắt đầu từ MAX để đảm bảo chưa có đường tìm thấy 
    for(int i = 0; i < dist_size; i++){
        dist[i] = INT_MAX;
    }
    //khoảng cách từ đỉnh xuất phát đến chính nó bằng 0
    dist[0] = 0; 
    
    // khoi tao gia tri cho hang doi uu tien
    for (int i = 0; i < dist_size; i++){
        q.push({i, dist[i]});
    }
    //bắt đầu lặp cho đến khi q rỗng 
    while (!q.empty()){
        pair<int, int> u_pair = q.top(); 
        q.pop();
        //lấy ra đỉnh có thứ tự ưu tiên cao nhất trong hàng đợi 
        int u = u_pair.first; 
        
        //duyệt qua các đỉnh kề của đỉnh hiện thời 
        for (auto v_pair : adj[u]){
            int v = v_pair.first;
            int weight = v_pair.second;
            
            /* nếu khoảng cạnh đỉnh hiện tại đến đỉnh kể cộng với trọng số cạnh
            nhỏ hơn khoảng cách hiện tại đến đỉnh kế thì cập nhật và đưa vào
            hàng đợi ưu tiên */
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                q.push({v, dist[v]});
            }
        }
    }
    //trả về khoảng cách từ đỉnh xuất phát đến các đỉnh còn lại 
    return dist;
    
    //*****************
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}