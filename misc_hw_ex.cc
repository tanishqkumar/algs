#include <iostream>
#include "helpers.hh"

typedef vector<vector<double>> matrix; 
using namespace std; 

vector<int> fib_iter(int len) {
    // iterative, takes linear time 
    vector<int> fibs = {0, 1};
    for (int i = 2; i < len; ++i){
        fibs.push_back(fibs[i-1]+fibs[i-2]);
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

vector<int> fib_mat(int len){
    
}

// add matrix mult for non-square matrices to able to multiply [1, 0] with the expon'd matrix
// add fast exponentiation
// use fast exponentiation to give fibonacci seq in logn time


int main() {
    auto chosen_fib_method = fib_rec; 
    int fib_arr_size = 20; 
    
    vector<int> fibs = chosen_fib_method(fib_arr_size);
    print_arr(fibs);
}