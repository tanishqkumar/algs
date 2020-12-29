#include <iostream>
#include <random>
#include <chrono>
#include <assert.h>
#include <algorithm>
#include <unordered_map>

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

vector<int> generate_unsorted_array(int a, int b, int n)
{
    // random number library stuff
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(a, b); // limits for number

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
    int number; // unique identifier - can be 0
    int parent;
    int distance_from_root;
    char color; // one of 'w', 'b', 'g'

    bool const operator==(const int num) const // define operator for handling map with this as key
    {
        return num == number;
    }
};

// struct vertexHasher
// {
//     size_t operator()(const vertex &v) const
//     {
//         using std::hash;
//         using std::size_t;
//         using std::string;

//         return ((hash<string>()(v.number) ^ (hash<string>()(v.color) << 1)) >> 1) ^ (hash<int>()(v.distance_from_root) << 1);
//     }
// };

// unordered_map<vertex, vector<vertex>, vertexHasher> generate_random_graph(int nv)
// { // takes input num_vert because num_edge makes life hard
//     // init vertices for construction of graph later
//     vector<vertex> all_vertices; 
//     for (int i = 0; i < nv; ++i){ 
//         vertex v; 
//         v.number = i; 
//         all_vertices.push_back(v);
//     }
    
//     unordered_map<vertex, vector<vertex>, vertexHasher> adj_list; 
//     for (int i = 0; i < nv; ++i){
//         vector<vertex> cur_v_conns;
//         // create vector of vertices we want this one vertex to connect to
//         int n_conns_for_cur_v = rand_int(1, 5);
//         for (int j = 0; j < n_conns_for_cur_v; ++j){ 
//             vertex rand_v = all_vertices[rand_int(0, all_vertices.size()-1)];
//             bool exists = false; 
//             for (auto conn: cur_v_conns){
//                 if (conn.number == rand_v.number) exists = true; 
//             } if (!exists) cur_v_conns.push_back(rand_v); // add rand_vertex as a connection to our current it it doesn't exist
//         }
//         adj_list.insert({all_vertices[i] : cur_v_conns});
//     }
//     return adj_list;
// }

// // need to print all the attributes of all the vertices to make sure we've visited them all 
// void print_graph(unordered_map<vertex, vector<vertex>, vertexHasher> adj_list){
//     cout << "the adj list of the graph is: " << endl; 
//     for (int i = 0; i < adj_list.size(); ++i){ // print each el in adj_list
//         cout << "vertex " << i << " state : " << endl;
//         cout << "connections: ";
//         for (int j = 0; j < adj_list[i].size(); ++j){
//             if (j == adj_list[i].size()-1){
//                 cout << adj_list[i][j].number << endl;
//             }
//             else{
//                 cout << adj_list[i][j].number << ", ";
//             }
//         }
//         // make vector<vertex> a feature of the vertex itself?
//     }
// }
