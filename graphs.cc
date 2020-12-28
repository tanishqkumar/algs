#include <iostream>
#include <random>
#include <chrono>
#include <assert.h>
#include <algorithm>
#include "helpers.hh"
#include <map>

using namespace std;

typedef vector<vector<vertex>> adj_list_type; 

// need to define bfs() which will take in a graph and modify it's state
    // so that all the nodes have the correct state


// ensure all vertices have unique connections and write bfs
int main(){ 
    adj_list_type adj_list = generate_random_graph(4); // random graph
    print_graph(adj_list); 
}


