/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <stdio.h>

int n; //Nhap vao so luong phan tu  
int* arr; //Nhap vao con tro tro den mang  

void printChild(int* a,int start,int end,int size){
	//Ham in ra tat ca day con cua mang
    for(int i = start; i <= end; i++){
        printf("%d ", *(a+i));
        //In ra cac phan tu trong mang  
    }
    printf("\n");
    if (end < size - 1) printChild(a, start, end + 1, size);
    //Neu end chua phai la phan tu cuoi, goi lai ham printChild voi end + 1  
    else{
        if (start < size - 1) printChild(a, start + 1, start + 1, size);
    //Neu end la phan tu cuoi, goi lai ham printChild voi start + 1 
    }
}

void input(int* a, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", (a+i));
    //Nhap vao mang a voi kich thuoc la size
    }
}

int main(){
	printf("Ha Vinh Phuoc - K66 DHBKHN \n");
    scanf("%d\n", &n);
    arr = new int[n]; //Cap phat bo nho cho mang 
    input(arr, n); //Goi ham input de nhap du lieu
    printf("Tat ca cac day con la: \n"); 
    printChild(arr, 0, 0, n); //Goi ham de in ra tat ca day con
}

//Ha Vinh Phuoc 20215455
