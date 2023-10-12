/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <stdio.h>

int counteven(int* arr, int size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0){
            count += 1;
        }
    }
    return count;    
}

int main(){ 
    int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
    printf("%d", counteven(arr, 8)); 
}    
    //Ha Vinh Phuoc 20215455

