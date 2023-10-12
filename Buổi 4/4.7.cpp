/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include<iostream>
#include<set>

using namespace std;

template<class T>
//hàm nhận vào a, b và trả về hợp của chúng 
set<T> set_union(const set<T> &a, const set<T> &b) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //tạo một tập hợp rỗng 
    set<T> c;
    //duyệt qua các phần tử của a
    for (T v : a){
        //chèn vào tập hợp c bằng hàm insert 
        c.insert(v);
    }
    //duyệt qua các phần tử của b 
    for(T v  : b){
        //chèn vào tập hợp c bằng hàm insert
        c.insert(v);
    }
    return c;
    
    //*****************
}

template<class T>
//hàm nhận vào a, b và trả về giao của nó 
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //khởi tạo tập rỗng 
    set<T> c;
    //duyệt qua các phần tử của a
    //kiểm tra xem với mỗi phần tử trong a có tồn tại trong b không 
    for (T v : a){
        int index = 0;
        for (T u : b){
            if (v == u) index++;
        }
        //nếu có thì lập tức gọi hàm insert để chèn 
        if (index != 0) c.insert(v);
    }
    return c;
    
    //*****************
}

template<class T>
//hàm dùng để in ra tất cả phần tử của tập hợp 
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);
    
    std::cout << "Union: "; print_set(c);
    std::cout << "Intersection: "; print_set(d);

    return 0;
}
//Ha Vinh Phuoc 20215455 