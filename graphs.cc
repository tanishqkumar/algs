#include <iostream>
#include <random>
#include <chrono>
#include <assert.h>
#include <algorithm>
#include "helpers.hh"
#include <unordered_map>

using namespace std;

typedef unordered_map<vertex, vector<vertex>, vertexHasher> adj_list_type; 

// need to define bfs() which will take in a graph and modify it's state
// adj_list_type bfs(adj_list_type adj_list, vertex root){
    // init attributes of root since we'll start there
    // add root to Q
    // while Q
        // v = deQ
        // add all children of v to Q, setting their parent as v and their distance from root as v.dist + 1
        // set v to black since we've fully explored it
// }

// ensure all vertices have unique connections and write bfs
int main(){
    adj_list_type adj_list = generate_random_graph(4); // random graph
    print_graph(adj_list);
}
