#include <iostream>
#define MAXSZ 10000

using namespace std;

// come back and implement using ll to make this stack dynamic
struct sstack {
    int arr[MAXSZ]; // actual arr to store stuff in 
    int top = -1; // index of where we currently are, init at -1 since we want the first thing to be put in at 0

    int size(){
        return top; 
    }

    bool push(int input){ // return input on success, and -1 on failure
        if (top >= MAXSZ)
            return false; 
        else
            arr[++top] = input; 
        return true; 
    }

    int peek(){
        return arr[top];
    }

    int pop(){
        if (top >= 0) 
            return arr[--top + 1];
        else return -1; 
    }

    bool isEmpty(){
        return (top == -1); 
    }
};

void print_stack(sstack s){
    for (int i = 0; i < s.size()+1; ++i){
        cout << s.arr[i]; 
    }
    cout << endl; 
    return; 
}


struct sq {
    int arr[MAXSZ];
    int head = 0; 
    int tail = 0; 

    bool eq(int input){
        
    }

}



int main(void){
}