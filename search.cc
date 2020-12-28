#include <iostream>
#include <random>
#include <chrono>
#include <assert.h>
#include <algorithm>
#include "helpers.hh"
#include <map>

using namespace std;

int linear_search(vector<int> input_arr, int el){ // returns index of found int 
    for (int i = 0; i < input_arr.size(); ++i){
        if (input_arr[i] == el){
            return i; 
        }  
    }
    return -1; // not found
}

// [1, 3, 5, 9, 10, 11, 18] looking for 3
int binary_search(vector<int> input_arr, int el){
    // sort it so we can use bsearch
    sort(input_arr.begin(), input_arr.end());
    // set mid point of input array
    int mid_index = int(input_arr.size() / 2);

    if (input_arr[mid_index] == el) {
        cout << "found el: " << el << " at index " << mid_index << endl; 
        return mid_index; 
    }
    else if (input_arr[mid_index] > el){
        // recurse over left half
        vector<int> subarr; 
        for (int i = 0; i < mid_index; ++i)
            subarr.push_back(input_arr[i]);
        return binary_search(subarr, el);
    }
    else if (input_arr[mid_index] < el){
        // recurse over the right half 
        vector<int> subarr;
        for (int i = mid_index + 1; i < input_arr.size(); ++i)
            subarr.push_back(input_arr[i]);
        return binary_search(subarr, el);
    }
    return -1; 
}



int main(){
    // settings
    // auto chosen_search_alg = binary_search; // choose your algorihtm
    int arr_len = 10;
    int num_tries = 1; // how many times you want it to run 

    for (int i = 0; i < num_tries; ++i){
        // driver code
        int rand_index = rand_int(0, arr_len - 1);
        vector<int> input_arr = generate_unsorted_array(arr_len); // needs to be unique here
        int rint = input_arr[rand_index];
        
        cout << "looking for rindex " << rand_index << " for int " << rint << " in the array ";
        print_arr(input_arr);

        int found_index = binary_search(input_arr, rint);

        cout << "found value was " << input_arr[found_index] << " at index " << found_index << endl;
        assert(input_arr[found_index] == input_arr[rand_index]); // check vals in case there are duplicates
    }
    cout << "search working!" << endl;
}