/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <iostream> 
using namespace std;
struct Node { 
    //cấu trúc đại diện cho node trong dslk 
    int data; //lưu giá trị cho node 
    Node* next; //trỏ đến node kế tiếtiếp

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    Node *tmp = new Node(data); //thêm node mới 
    //nếu dslk rỗng, node vừa tạo trở thành head 
    if (head == NULL){
        head = tmp;
        return head;
    }
    //nếu không thì node vừa tạo trỏ đến head và thành head mới 
    tmp->next = head;
    return tmp;
    
    //*****************
}

// print the list content on a line
void print(Node* head) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    if (head == NULL){
        cout << endl;
        return;
    }
    //đệ quy in ra giá trị của tất cả các nốt trên một dòng 
    cout << head->data << " ";
    head = head ->next;
    print(head);
    //*****************
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    if (head == NULL) return NULL;
    Node *p = head;
    Node *h = head;
    Node *q;
    p = p->next;
    //duyệt qua dslk từ đầu đến cuối 
    while (p != NULL){
        //thay đổi con trỏ để đảo ngược 
        q = p;
        p = p->next;
        q->next = head;
        head = q;
    }
    //trả về head mới 
    h->next = NULL;
    return head;
    //*****************
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
//Ha Vinh Phuoc 20215455