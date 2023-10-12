/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <stdio.h>

int lucas(int n) {
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    if (n <= 1) return 2 - n; 
	//Neu n<= 1 tra ve gia tri (2 - n) 
    return lucas(n - 1) + lucas(n - 2);
    //Neu khong thi goi ham de quy tinh gia tri L[n-1] vaf L[n-2]
    
    //*****************
}

int main() {
    for (int n = 0; n <= 10; n++){
    	//Voi gia tri cua n tu 0 den 10 goi ham lucas de in ket qua
        printf("L[%d] = %d\n", n, lucas(n));
    	//In ra man hinh cac gia tri
    }
    return 0;
}
