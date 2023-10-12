/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <iostream>

using namespace std;

int n; 
int X[100], Y[100]; 
int mark[100][100];

const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};


void print_sol(){
    for (int j = 1; j <= n * n; j++){
        cout << "(" << X[j] << " " << Y[j] << ")" << endl;
    }
    exit(0);
}

bool ifpossible(int x, int y){
    if (x < 1 || x > n) return false; 
    if (y < 1 || y > n) return false;
    if (mark[x][y] == 1) return false;
    return true;
}

void TRY(int k){
    for (int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        
        //*****************
        /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
        
        if (ifpossible(xx, yy)){
            
            mark[xx][yy] = 1; 
            X[k] = xx; 
            Y[k] = yy; 
            if (k == n*n) print_sol();
            TRY(k+1);
            mark[xx][yy] = 0;
        
        //*****************
        }
    }
}

int main(){
    cin >> n; 
    mark[1][1] = 1;
    X[1] = Y[1] = 1; 
    TRY(2);
    return 0;
}
//Ha Vinh Phuoc 20215455 
