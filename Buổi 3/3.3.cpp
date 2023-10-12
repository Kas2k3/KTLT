/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; 
int cmin = INT_MAX;
int best = INT_MAX; 
int curr; 
int mark[MAX]; 
int x[MAX]; 

void input(){
    cin >> n; 
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j]; 
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

void TRY(int k){
    for(int i = 2; i <= n; i++){ 
        //*****************
        /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
        
        if (!mark[i]) { 
            x[k] = i;
            mark[i] = 1; 
            curr += c[x[k - 1]][i];  
            if (k == n) best = min(best, curr + c[i][1]);
            else if (curr + cmin * (n - k + 1) < best) TRY(k + 1);
            mark[i] = 0; 
            curr -= c[x[k - 1]][i];
        
        //*****************
    
        }
    }
}


int main(){
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
//Ha Vinh Phuoc 20215455
