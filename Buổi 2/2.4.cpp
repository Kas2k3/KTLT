/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */
#include <stdio.h>

int cube(int x) {
//*****************
/* YOUR CODE HERE Ha Vinh Phuoc 20215455 */

    return x*x*x;

//*****************
}

//*****************
/* YOUR CODE HERE Ha Vinh Phuoc 20215455 */

double cube(double x){
    return x*x*x;
}    

//*****************

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f); 
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}
//Ha Vinh Phuoc 20215455
