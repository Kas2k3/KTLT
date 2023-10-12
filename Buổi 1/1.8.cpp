/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <stdio.h>

void allocate_mem(int ***mt, int m, int n){
    //#Allocate memory for the matrix
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    *mt = new int*[m];
    for (int i = 0; i < m; i++){
        (*mt)[i] = new int[n];
        }
    //*****************
    }

void input(int **mt, int m, int n){
    //#Input elements of the matrix
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("mt[%d][%d] = ", i, j);
            scanf("%d", &mt[i][j]);
        }
    }
    //*****************
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
        printf("%d ", mt[i][j]);
        }
        printf("\n");
    }   
    //*****************
    
}

int process(int **mt, int m, int n){
    int tong = 0;
    //# Calculate the sum of all even elements in the matrix
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (mt[i][j] % 2 == 0){
                tong += mt[i][j];
            }
        }
    }
    //*****************
    
    return tong;
}

void free_mem(int **mt, int m, int n){
    //# Free memory
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    delete [] mt;
    //*****************
    
}

int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}
//Ha Vinh Phuoc 20215455 
