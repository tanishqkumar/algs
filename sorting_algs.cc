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
        if (i == arr.size()-1) // last char without comma and with \n instead
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


vector<int> insertion_sort(vector<int> input_arr){ 
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
    assert(is_sorted(input_arr.begin(), input_arr.end()));
    return input_arr;
}


int main()
{   
    auto sorting_alg = insertion_sort; // choose your algorithm at the beginning and everything else just works

    int arr_len = 100;
    vector<int> input_arr = generate_unsorted_array(arr_len);
    cout << "before: ";
    print_arr(input_arr);

    input_arr = sorting_alg(input_arr); // doesn't mutate because c++ passes vector by value

    cout << "after : ";
    print_arr(input_arr);
}