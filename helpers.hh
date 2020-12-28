#include <iostream>

using namespace std; 


// OVERALL HELPERS
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
    uniform_int_distribution<> distr(1, 10000); // limits for number

    vector<int> random_ints_arr;
    for (int i = 0; i < n; ++i)
    {
        random_ints_arr.push_back(distr(gen));
    }
    return random_ints_arr;
}

// vector<int> generate_unique_unsorted_array(int n)
// {
//     // random number library stuff
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> distr(1, 10000); // limits for number

//     vector<int> random_ints_arr;
//     for (int i = 0; i < n; ++i)
//     {
//         int rint = distr(gen); // initial rint 
//         while (any_of_equal(random_ints_arr.begin(), random_ints_arr.end(), rint)){
//             int rint = distr(gen); // keep generating new numbers until we get one not already in the array
//         }
//         random_ints_arr.push_back(distr(gen));
//     }
//     return random_ints_arr;
// }

int rand_int(int a, int b){
    // random number library stuff
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(a, b); // limits for number
    return distr(gen);
}

// GRAPH HELPERS

// vertex object with parent, distance from root, color
struct vertex
{
    int number; // unique identifier
    int parent;
    int distance_from_root;
    char color; // one of 'w', 'b', 'g'
};

// then represent graph as adj list via vector<vector<vertex>> with an entry for each vertex


// write generate_random_graph function in helpers.hh










