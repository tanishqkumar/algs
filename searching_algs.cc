#include <iostream>
#include <random>
#include <chrono>
#include <assert.h>
#include <algorithm>
#include "helpers.hh"
#include <unordered_map>

using namespace std;

int linear_search(vector<int> input_arr, int el){ // returns index of found int 
    for (int i = 0; i < input_arr.size(); ++i){
        if (input_arr[i] == el){
            return i; 
        }  
    }
    return -1; // not found
}

// binary search was slower since input_arr was being copied every time, which takes linear time, so was total O(nlogn)
    // whereas by reference there is no copying and it becomes truly O(logn)
// recursion is also unecessary and slows down code by having more overhead
    // while an iteration just involve `cmp` and `jmp` over and over
    // with recursion you have to load up registers for new function call
        // and save current register state for those that aren't callee-saved
    // ensure stack is in order (i.e. not about to overflow or at red zone)
// in general for performant/production applications use recursion when iteration would involve very messy or complex data structures
    // since you're balancing production time vs development time (recursion is more elegant and easier to understand)
    // recursion gave avg. time for array of 100K els as 320 nanosecs, and iteration gave 260 nanosecs!
int binary_search(vector<int>& input_arr, int l, int r, int el){ 
    while (l < r){
        int mid_index = int((l+r)/2);
        
        if (input_arr[mid_index] == el) {
            return mid_index;
        }
        else if (input_arr[mid_index] > el){
            r = mid_index - 1; 
        }
        else if (input_arr[mid_index] < el){
            l = mid_index + 1; 
        }
    }
    return -1; 
}

int main(){
    // settings
    int arr_len = 100000;
    int num_tries = 100; // how many times you want it to run 

    unsigned long long total_time_bsearch = 0; 

    for (int i = 0; i < num_tries; ++i){
        // driver code
        int rand_index = rand_int(0, arr_len - 1);
        vector<int> input_arr = generate_unsorted_array(1, 1000, arr_len); // needs to be unique here
        sort(input_arr.begin(), input_arr.end()); // assume sorted
        int rint = input_arr[rand_index];
        
        // cout << "looking for rindex " << rand_index << " for int " << rint << " in the array ";
        int found_index = binary_search(input_arr, 0, input_arr.size()-1, rint);
        assert(input_arr[found_index] == input_arr[rand_index]); // check vals in case there are duplicates

        // cout << "found value was " << input_arr[found_index] << " at index " << found_index << endl;
    }
    cout << "search working!" << endl;
}