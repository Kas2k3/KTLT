/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) { 
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    return sqrt(x*x+y*y);
    
    //*****************
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y); 
    
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z); 
    
    return 0;
}

