
#include <stdio.h>
#include <stdlib.h>

int Fibonacci_Search(int array[], int array_length, int key){
    int* Fibonacci_sequence = malloc(array_length*sizeof(int));
    // Create Fibonacci sequence
    Fibonacci_sequence[0] = 0;
    Fibonacci_sequence[1] = 1;
    for(int i = 2; i < array_length; i++){Fibonacci_sequence[i] = Fibonacci_sequence[i-1] + Fibonacci_sequence[i-2];}
    // y is the number of Fibonacci sequence elements which smaller than the size of Fibonacci sequence
    int y = 0;
    while(Fibonacci_sequence[y] <= array_length) {y++;}
    y--;
    //Based on the formula F_y + m = n => m = n - F_y
    int m = array_length - Fibonacci_sequence[y];
    // Based on x = y - 1
    int x = y - 1;
    /*
    if the reference point of Fibonacci sequence is smaller than the number of what we want,
    shift m position to the new reference point.
    */
    int x_tmp=0;
    if(Fibonacci_sequence[x_tmp] < key) {x_tmp += m;}
    // Search
    int result = -1;
    while(Fibonacci_sequence[x] > 0) {
        if(array[x_tmp] < key)
            x_tmp += Fibonacci_sequence[--x];
        else if(array[x_tmp] > key)
            x_tmp -= Fibonacci_sequence[--x];
        else {
            result = x_tmp;
            break;
        }
    }
    free(Fibonacci_sequence);
    return result;
}
