/* Ha Vinh Phuoc 20215455
Ma lop thuc hanh: 727638 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 128;

struct Matrix { //Khai bao cau truc ma tran
    unsigned int mat[N][N]; //Mang 2 chieu chua cac phan tu 

    Matrix() {
        memset(mat, 0, sizeof mat);
    }
};

bool operator == (const Matrix &a, const Matrix &b) { 
//So sanh 2 ma tran a va b
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a.mat[i][j] != b.mat[i][j]) return false;
            //Neu cac phan tu cua 2 ma tran khac nhau thi tra ve false
        }
    }
    return true; //Nguoc lai thi tra ve true
}

Matrix multiply_naive(const Matrix &a, const Matrix &b) {
	//Ham nhan ma tran voi toc do cham hon
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}

Matrix multiply_fast(const Matrix &a, const Matrix &b) {
	//Ham nhan ma tran voi toc do nhanh hon
    //*****************
    /* YOUR CODE HERE Ha Vinh Phuoc 20215455 */
    
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += a.mat[i][k] * b.mat[k][j];
            }
            c.mat[i][j] = sum;
        }
    }
    return c;
   
    //*****************
}

Matrix gen_random_matrix() {
	//Ham tra ve mot ma tran ngau nhien
    Matrix a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a.mat[i][j] = rand();
        }
    }
    return a;
}

Matrix base;

double benchmark(Matrix (*multiply) (const Matrix&, const Matrix&), Matrix &result) {
    //Ham danh gia thoi gian thuc hien
	const int NUM_TEST = 10;
    const int NUM_ITER = 64;

    Matrix a = base;
    result = a;

    double taken = 0;
    for (int t = 0; t < NUM_TEST; ++t) {
        clock_t start = clock();
        for (int i = 0; i < NUM_ITER; ++i) {
            a = multiply(a, result);
            result = multiply(result, a);
        }
        clock_t finish = clock();
        taken += (double)(finish - start);
    }
    taken /= NUM_TEST;

    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

int main() {
    base = gen_random_matrix();

    Matrix a, b;
    printf("Slow version\n");
    double slow = benchmark(multiply_naive, a);
    printf("Fast version\n");
    double fast = benchmark(multiply_fast, b);

    if (a == b) {
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
    } else {
        printf("Wrong answer!\n");
    }
    return 0;
}
//Ha Vinh Phuoc 20215455
