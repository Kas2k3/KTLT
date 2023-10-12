/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <iostream>
#include <map>

using namespace std;

template<class T>
//hàm biểu diễn hợp của hai tập mờ 
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //khởi tạo map rỗng 
    map<T, double> c;
    //kiểm tra có tồn tại phần tử thuộc a và cả b không 
    for (auto v : a){
        int index = 0;
        for (auto u : b){
            //nếu có thì chèn vào map c giá trị lớn hơn 
            if (v.first == u.first){
                c.insert({v.first, max(v.second, u.second)});
                index++;
                break;
            }
        }
        /* nếu không có thì chèn phần tử vào map c 
        với giá trị tương ứng trong a */
        if (index == 0) c.insert({v.first, v.second});
    }
    
    //duyệt qua các phần tử trong b
    for (auto v : b){
        int index = 0;
        //kiểm tra nó có tồn tại trong cả tập a không 
        for (auto u : a){
            if (v.first == u.first){
                //nếu có thì chèn vào map c giá trị lớn hơn 
                c.insert({v.first, max(v.second, u.second)});
                index++;
                break;
            }
        }
        
        /* nếu không có thì chèn phần tử vào map c 
        với giá trị tương ứng trong b */
        if (index == 0) c.insert({v.first, v.second});
    }
    return c;
    
    //*****************
}

template<class T>
//hàm biểu diễn giao của 2 tập mờ 
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    //khởi tạo map rỗng 
    map<T, double> c;
    //duyệt qua các phần tử trong a
    //kiểm tra phần tử có cùng key tồn tại trong b không 
    for (auto v : a){
        for (auto u : b){
            //nếu tồn tại thì chèn vào map c giá trị nhỏ hơn 
            if (v.first == u.first){
                c.insert({v.first, min(v.second, u.second)});
                break;
            }
        }
    }
    return c;
    
    //*****************
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
//Ha Vinh Phuoc 20215455