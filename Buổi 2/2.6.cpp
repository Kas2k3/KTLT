/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */
#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n);
}

int mul3plus1(int n) {
    return n * 3 + 1;
}

int div2(int n) {
    return n / 2;
}

// khai báo các tham s? cho các con tr? hàm odd, even và output
void simulate(int n, /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */ int (*odd)(int),int (*even)(int),void (*output)(int) )  {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}

int main() {
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    int (*odd)(int) = mul3plus1;
    int (*even)(int) = div2;
    
    //*****************

    int n;
    scanf("%d", &n);
    simulate(n, odd, even, print);

    return 0;
}
