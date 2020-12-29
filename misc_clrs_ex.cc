#include <iostream>
#include "helpers.hh"

using namespace std;

// take in [2, 5, -3, -1, 6]
// output indices of max subarray, and the sum it gives
tuple<int, int, int> max_cross_subarray(vector<int> input_arr, int low_index, int mid_index, int high_index)
{
    int max_left_sum = -10001; // rlly small init val
    int max_left_index = low_index;
    int pot_sum_l = 0;
    // check left half incrementally from mid down to low and
    for (int i = mid_index; i >= low_index; --i)
    {
        pot_sum_l += input_arr[i];
        if (pot_sum_l > max_left_sum)
        {
            max_left_sum = pot_sum_l;
            max_left_index = i;
        }
    }

    int max_right_sum = -10001; // rlly small init val
    int max_right_index = high_index;
    int pot_sum_r = 0;
    // check right half
    for (int i = mid_index; i <= high_index; ++i)
    {
        pot_sum_r += input_arr[i];
        if (pot_sum_r > max_right_sum)
        {
            max_right_sum = pot_sum_r;
            max_right_index = i;
        }
    }
    return make_tuple(max_left_index, max_right_index, max_left_sum + max_right_sum);
}

// max subarray problem
// take in [-2, 4, 3, -5, 6, 2, -1]
// return indices i, j such that j > i and j-i is maximized
tuple<int, int, int> max_subarray(vector<int> input_arr, int low_index, int high_index){
    if (low_index == high_index) return make_tuple(low_index, high_index, input_arr[low_index]);
    int mid_index = int((low_index + high_index)/2);
    // find max-left via recurse
    int max_left_i, max_left_j, max_left_sum;
    tie(max_left_i, max_left_j, max_left_sum) = max_subarray(input_arr, low_index, mid_index);
    // find max-right via recurse
    int max_right_i, max_right_j, max_right_sum;
    tie(max_right_i, max_right_j, max_right_sum) = max_subarray(input_arr, mid_index+1, high_index);
    // find max-cross using helper find_max_cross_subarray
    int max_cross_i, max_cross_j, max_cross_sum;
    tie(max_cross_i, max_cross_j, max_cross_sum) = max_cross_subarray(input_arr, low_index, mid_index, high_index);
    // return whichever of the three is largest
    if ((max_left_sum >= max_cross_sum)
        &&(max_left_sum >= max_right_sum)) return make_tuple(max_left_i, max_left_j, max_left_sum);
    if ((max_right_sum >= max_cross_sum)
        &&(max_right_sum >= max_left_sum)) return make_tuple(max_right_i, max_right_j, max_right_sum);
    else
        return make_tuple(max_cross_i, max_cross_j, max_cross_sum);
}

int main(){
    vector<int> input_arr = generate_unsorted_array(-5, 20, 5);
    print_arr(input_arr);

    int max_i, max_j, max_sum; 
    tie(max_i, max_j, max_sum) = max_subarray(input_arr, 0, input_arr.size()-1);

    cout << "start index is " << max_i << " and end is " << max_j << " to give sum of " << max_sum << endl;

    // int acc_max_i, acc_max_j, acc_max_sum = -10001; 
    // for (int i = 0; i < input_arr.size(); ++i){
    //     for (int j = i; j < input_arr.size(); ++j){
    //         // sum input_arr[i:]
    //     }
    // } 
    // iterate through all combinations using brute force and check answer is indeed the highest possible sum
}