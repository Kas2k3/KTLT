/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <stdio.h> 

void reversearray(int arr[], int size){
    int r = size - 1, tmp;
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    for (int i = 0; i <= r/2; i++){
        tmp = arr[i];
        arr[i] = arr[r-i];
        arr[r-i] = tmp;
    }
    //*****************
}

void ptr_reversearray(int *arr, int size){
    int r = size - 1, tmp;
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    for (int i = 0; i <= r/2; i++){
        tmp = arr[i];
        arr[i] = arr[r-i];
        arr[r-i] = tmp;
    }
    //*****************
}

int main(){
	int arr[] = {9, 3, 5, 6, 2, 5};
	reversearray(arr, 6);
	for(int i = 0; i < 6; i++) printf("%d ", arr[i]);
	int arr2[] = {4, -1, 5, 9};
	ptr_reversearray(arr2, 4);
	for(int i = 0; i < 4; i++) printf("%d ", arr2[i]);	
} 
//Ha Vinh Phuoc 20215455
