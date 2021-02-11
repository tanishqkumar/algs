#include <iostream>
#include <cfloat>
// #include "..helpers.hh"

using namespace std; 

#define ull unsigned long long; 
#define MAX_NUM_DIM 4;
#define graph vector<vector<float> >;

// ASSIGNMENT DETAILS
    // complete, undirected graphs only => nC2 vertices for n edges

// high level design
// for (int dim = 0; dim < MAX_NUM_DIM; ++dim){
    // for (ull n = 0; n < )
    // construct_complete_undir_graph(dim, vert);
// }

// extra ideas
    // systems explanations for asymptotic deviations, eg. cache lines
    // write our own rnd_gen, maybe using coin flips idea?
    // try a few diff algs (eg. kruskal, reverse_delete)
    // higher dimensions (eg. up to 100)


static const int num_vertices_list[] = { 
    128, 
    256, 
    512, 
    1024, 
    2048, 
    4096, 
    8192, 
    16384, 
    32768, 
    65536, 
    131072, 
    262144
}; 

struct vertex{
    int dim; 
    // (0.3, 0.5, 0.1)
}; 

struct edge{
    vertex from; 
    vertex to; 
}; 

// edge gen_random_edge(int dim){
// }

ull num_vert_to_num_edge (ull num_vert){
    // return num_vert CHOOSE 2r
}

struct complete_graph{
    int num_vert; 
    int num_dim;
    vector<vector<float> > adj_list = {{}};
};



// struct complete_graph{
    // store vertices in an array since no dynamic resizing required
    // store edges as an array of pairs

// }

// complete_graph generate_rand_graph(int num_vert, int dim){

// }

int main(){
    cout << "yolo";
}


