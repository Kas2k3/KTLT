/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; 

void init(){
    memset(mem, -1, sizeof(mem));
}

int lis(int i) {
    
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    if (mem [i] != -1) {
        return mem[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) {
            res = max(res, 1 + lis(j));
        }
    }
    mem[i] = res;
    return res;
    
    //*****************
}

void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
//Ha Vinh Phuoc 20215455 
