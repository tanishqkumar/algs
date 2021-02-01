#include "helpers.hh"
#include <iostream>

using namespace std; 


string alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

// runs in O((n-m+1)m) time
int naive_str_match(string pattern, string text){
    int m = pattern.length();
    int n = text.length();

    // find the pattern string in the text string
    for (int i = 0; i < n - m + 1; ++i)
    {
        if (pattern.compare(text.substr(i, m)) == 0) return i;
    }
    return -1; 
}

int rabin_karp(string pattern, string text){
    // uses rolling hashes to get better actual performance
}

int main(){; 
    cout << naive_str_match("ef", alphabet) << endl; 
}