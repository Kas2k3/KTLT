/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */
#include <stdio.h>

//*****************
/* YOUR CODE HERE Ha Vinh Phuoc 20215455 */

    int get_value(int x, int a=2, int b=1, int c=0){
        return x*x*a + x*b + c;
    }
//*****************

int main(){
    int x;
    scanf("%d", &x);
    
    int a = 2; //# gi� tr? m?c �?nh c?a a
    int b = 1; //# gi� tr? m?c �?nh c?a b
    int c = 0; //# gi� tr? m?c �?nh c?a c
    
   //*****************
/* YOUR CODE HERE Ha Vinh Phuoc 20215455 */

    scanf("%d%d%d",&a,&b,&c);

//*****************
    
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    
    return 0;
}
