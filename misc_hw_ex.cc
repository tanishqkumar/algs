#include <iostream>
#include <unordered_map>
#include "helpers.hh"

using namespace std;
#define N 2
const int mod = 1e9+7;
#define matrix vector<vector<int>>
const matrix id_mat_2x2 = {{1, 0}, {0, 1}};

int dot(vector<int> A, vector<int> B){
    int sum = 0; 
    assert(A.size() == B.size()); // used in matmul
    for(int i = 0; i < A.size(); ++i){
        sum += A[i] * B[i]; 
        sum %= mod; 
    }
    return sum; 
}

vector<int> col(matrix X, int k){
    // take in matrix and the column we want, return the column as a row vector
    vector<int> col_as_row_vec; 
    for(int i = 0; i < X.size(); ++i){
        col_as_row_vec.push_back(X[i][k] % mod);
    }
    return col_as_row_vec; 
}

matrix matrix_mult(matrix A, matrix B){
    int h_a = A.size();
    int w_a = A[0].size();
    
    int h_b = B.size();
    int w_b = B[0].size();

    assert(h_a == w_b); // check dimensions 

    matrix C; // output
    for(int i=0; i < h_a; ++i){
        vector<int> buf; 
        for(int j=0; j < w_b; ++j){
            int res = dot(A[i], col(B, j));
            buf.push_back(res % mod);
        }
        C.push_back(buf);
    }
    return C;
}

void print_mat(matrix A){
    int h = A.size();
    int w = A[0].size();
    for(int i=0; i < h; ++i){
        for(int j=0; j < w; ++j){
            cout << A[i][j] << " ";
        }
        cout << endl; 
    }
}

vector<int> fib_iter(int len) {
    // iterative, takes linear time 
    vector<int> fibs = {0, 1};
    unsigned long long max = long(2) << 31; 
    for (int i = 2; i < len; ++i){
        int num = fibs[i - 1] + fibs[i - 2]; 
        fibs.push_back(num);
        if (num >= max) break; 
    }
    return fibs; 
}

// returns first to take more tha na minute
vector<int> fib_iter_mod(int len)
{
    // iterative, takes linear time
    vector<int> fibs = {0, 1};
    for (int i = 2; i < len; ++i)
    {
        int num = (fibs[i - 1] + fibs[i - 2]) % mod;
        fibs.push_back(num);
    }
    return fibs;
}

int get_fib_el(int n){
    if (n == 0) return 0; 
    if (n == 1) return 1; 
    return (get_fib_el(n-1) + get_fib_el(n-2));
}

vector<int> fib_rec(int len){
    // recursive, takes exponential time because every element spawns twins 
    vector<int> fibs = {0, 1};
    for (int i = 2; i < len; ++i){
        fibs.push_back(get_fib_el(i));
    }
    return fibs;
}

matrix fast_mat_exp(matrix A, int n){
    // A^n in O(logn) time
    if (n == 1) return A; 
    matrix res = id_mat_2x2; 
    while(n > 0){
        if (n % 2 == 1) res = matrix_mult(res, A);
        A = matrix_mult(A, A);
        n/=2; 
    }
    return res; 
}


vector<int> fib_matrix(int len){
    matrix base_matrix = { {0, 1},
                         {1, 1} };
    vector<int> fibs = {0, 1}; 
    for (int i = 2; i < len; ++i){
        matrix res = fast_mat_exp(base_matrix, i-1); 
        int new_fib = res[0][1] % mod; 
        fibs.push_back(new_fib);
    }
    return fibs; 
}

// modify to return whole array and properly mod 2^16
int main() {
    int fib_arr_size = 100;

    auto start = chrono::high_resolution_clock::now();
    vector<int> fibs;
    fibs = fib_matrix(fib_arr_size); // get fibonaccis
    auto stop = chrono::high_resolution_clock::now();

    auto time = (stop - start).count() / quick_pow10(6); // normally in ns, so qp(6) is to change to ms
    print_arr(fibs);

    cout << "time taken for generating the first " << fib_arr_size << " numbers was " << time
         << " ms which is " << (stop - start).count() << " nanosecs and thus " << (stop - start).count() / quick_pow10(9) << " seconds" << endl;

}