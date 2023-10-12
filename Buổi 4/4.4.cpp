/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//hàm in các phần tử trong vector trên một dòng 
void print_vector(const vector<int> &a) {
    //duyệt qua các phần tử 
    for (int v : a) cout << v << ' ';
    cout << endl;
}

//hàm xóa các phần tử chẵn trong vector 
void delete_even(vector<int> &a) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //xóa đi các phần tử bằng hàm erase và remove 
    a.erase(remove_if(a.begin(), a.end(), [](int a){
        return (a%2 == 0);
    }), a.end());
    
    //*****************

}

//hàm sắp xếp giảm dần các phần tử trong vector 
void sort_decrease(vector<int> &a) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //sắp xếp thông qua hàm sort 
    sort(a.rbegin(), a.rend());
    
    //*****************
}

//hàm trộn 2 vector vào một, các phần tử theo thứ tự giảm dần 
vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //tạo vector c để lưu trữ
    vector<int> c;
    //duyệt qua các phần tử để thêm vào vector c 
    for (int v : a){
        c.push_back(v);
    }
    for (int v : b){
        c.push_back(v);
    }
    //gọi hàm sort để sắp xếp một lần nữa 
    sort(c.rbegin(), c.rend());
    //trả về giá trị của vector mới 
    return c;
    
    //*****************
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
//Ha Vinh Phuoc 20215455 