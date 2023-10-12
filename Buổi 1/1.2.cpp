/* Ha Vinh Phuoc 20215455 
Ma lop thuc hanh: 727638 */

#include<stdio.h>

int main(){
    int a[7] = {13, -355, 235, 47, 67, 943, 1222};
	printf("\n Ha Vinh Phuoc - K66 DHBKHN \n");
    printf("address of first five elements in memory.\n");
    for(int i = 0; i < 5; i++) printf("\ta[%d]  \t\t",i); //In ra 5 phan tu dau 
    printf("\n");
    for(int i = 0; i < 5; i++)  printf("      %p ",&a[i]); //In ra dia chi 5 phan tu dau 
    return 0;
}

