#include <iostream>
#include <random>
#include <chrono>
#include <assert.h>
#include <algorithm>

using namespace std;

void print_arr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (i == arr.size() - 1) // last char without comma and with \n instead
            cout << arr[i] << endl;
        else
            cout << arr[i] << ", ";
    }
}

int quick_pow10(int n)
{
    static int pow10[10] = {
        1, 10, 100, 1000, 10000,
        100000, 1000000, 10000000, 100000000, 1000000000};

    return pow10[n];
}

vector<int> generate_unsorted_array(int n)
{
    // random number library stuff
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 1000); // limits for number

    vector<int> random_ints_arr;
    for (int i = 0; i < n; ++i)
    {
        random_ints_arr.push_back(distr(gen));
    }
    return random_ints_arr;
}

vector<int> insertion_sort(vector<int> input_arr)
{
    for (int j = 1; j < input_arr.size(); ++j)
    {
        int key = input_arr[j];
        int i = j - 1;
        while (i >= 0 && input_arr[i] > key)
        {
            input_arr[i + 1] = input_arr[i]; // shift everything down by one to make space for insertion of key
            i -= 1;
        }
        input_arr[i + 1] = key;
    }
    return input_arr;
}

vector<int> merge(vector<int> l, vector<int> r)
{
    // merge left and right arrays and return merged
    vector<int> merged_arr;
    // add sentinels so we know when l, r are empty
    l.push_back(-1);
    r.push_back(-1);
    // iterators for pairwise comparions
    int i = 0;
    int j = 0;
    while (l[i] != -1 || r[j] != -1)
    { // while we still have stuff in l,r
        // cases where we've used up everything in one input
        if (l[i] == -1)
        {
            for (int n = j; n < r.size() - 1; ++n)
                merged_arr.push_back(r[n]);
            return merged_arr;
        }
        else if (r[j] == -1)
        {
            for (int n = i; n < l.size() - 1; ++n)
                merged_arr.push_back(l[n]);
            return merged_arr;
        }
        else if (l[i] <= r[j])
        {
            // compare l[i] and r[j] and push larger to merged_arr
            merged_arr.push_back(l[i]);
            ++i;
        }
        else
        {
            merged_arr.push_back(r[j]);
            ++j;
        }
    }
    print_arr(merged_arr);
    return merged_arr;
}

vector<int> merge_sort(vector<int> input_arr)
{
    // check base case
    if (input_arr.size() == 1)
        return input_arr;
    // divide input_arr into l and r
    int middle = int(input_arr.size()) / 2;
    vector<int> l;
    for (int n = 0; n < middle; ++n)
        l.push_back(input_arr[n]);
    vector<int> r;
    for (int n = middle; n < input_arr.size(); ++n)
        r.push_back(input_arr[n]);
    
    l = merge_sort(l);
    r = merge_sort(r);
    vector<int> m = merge(l, r);

    return m;
}


vector<int> bubble_sort(vector<int> input_arr){
    bool swapped;
    do { // continue passing through list until we go through a pass without swapping
        swapped = false;
        for (int i = 1; i < input_arr.size(); ++i){
            if (input_arr[i] < input_arr[i-1]){
                swap(input_arr[i], input_arr[i-1]);
                swapped = true; // yes, we had to swap two items
            }
        }
    } while (swapped); // should only need to happen input_arr.size() # of times
    return input_arr;
}

// most often used IRL because the constant factors on nlgn are very low
vector<int> quick_sort(vector<int> input_arr){
    // input_arr = partition(input_arr)
    // q = input_arr.pop_back() // this is the value of the pivot
    // l = quick_sort(input_arr[0:q])
    // r = quick_sort(input_arr[q:end])
    // return [l, r] // l, r are sorted so just mush them together and return
}


// [1, 4, 5, 2, 8, 3]
vector<int> partition(vector<int> input_arr){ // store q as the last element, then pop it above
    // int r = input_arr.size();
    // pivot_val = input_arr[r]
    // int i = -1
    // int j = 0
    // for j: 0 to r    
        // if input_arr[j] > pivot_val
            // add to 
}

int main()
{
    // settings
    auto chosen_sorting_alg = bubble_sort; // choose your algorihtm
    int arr_len = 1000; 

    // driver code
    vector<int> input_arr = generate_unsorted_array(arr_len);
    
    cout << "before: ";
    print_arr(input_arr);
    
    // auto start = chrono::high_resolution_clock::now();
    
    vector<int> sorted_arr = chosen_sorting_alg(input_arr);
    
    // auto stop = chrono::high_resolution_clock::now();
    // auto time_for_merge = (stop - start).count() / quick_pow10(4); 
    
    assert(is_sorted(sorted_arr.begin(), sorted_arr.end()));

    cout << "after : ";
    print_arr(sorted_arr);
}