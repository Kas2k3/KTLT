/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Hàm tính diện tích hình chữ nhật lớn nhất từ các cột
long long largestRectangleArea(vector<long long>& heights) {
    stack<long long> st; // Stack lưu trữ chỉ số các cột tăng dần
    long long maxArea = 0; // Biến lưu trữ diện tích lớn nhất tìm được
    long long i = 0; // Chỉ số cột hiện tại

    while (i < heights.size()) {
        if (st.empty() || heights[i] >= heights[st.top()]) {
            // Nếu stack rỗng hoặc chiều cao của cột hiện tại lớn hơn hoặc bằng cột trên đỉnh stack
            // Đẩy chỉ số cột hiện tại vào stack và tăng chỉ số cột
            st.push(i);
            i++;
        } else {
            // Nếu chiều cao của cột hiện tại nhỏ hơn cột trên đỉnh stack
            // Lấy chiều cao của cột trên đỉnh stack và tính diện tích hình chữ nhật
            long long tp = st.top();
            st.pop();
            long long area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
            maxArea = max(maxArea, area);
        }
    }

    // Kiểm tra các cột còn lại trong stack
    while (!st.empty()) {
        long long tp = st.top();
        st.pop();
        long long area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> heights(n);
    for (long long i = 0; i < n; i++) {
        cin >> heights[i];
    }
    long long result = largestRectangleArea(heights);
    cout << result << endl;
    return 0;
}