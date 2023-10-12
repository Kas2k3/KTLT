/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */
#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    int temp = x;
    x = y;
    y = z;
    z = temp;
    
    //*****************
}

int main() {
    int x, y, z;

    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    scanf("%d%d%d", &x, &y, &z);
    
    //*****************
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}
