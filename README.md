# COMPSCI 377 Exercise: Memory Allocation

## Purpose
This exercise is designed to cover various aspects of memory in C/C++: the `new` and `delete` keywords, pointers, and how to manipulate memory. Please ensure that all your answers to questions in these exercises are done on the Edlab environment – otherwise, they may be inconsistent results and will not receive points. Please read through this document and follow the instructions. After you do that, visit Gradescope and complete the questions associated with this exercise by the assigned due date.

##Setup
Once you have logged in to Edlab, you can clone this repo using
```
https://github.com/umass-cs-377/F22-377-exercise-memory-allocation
```
Then you can use cd to open the directory you just cloned:
```
cd F22-377-memory-allocation
```
This repository includes a Makefile that allows you to locally compile and run all the sample code listed in this tutorial. You can compile them by running make. Feel free to modify the source files yourself. After making changes, you need to run `make` again to build new binaries from your modified files. You can also use `make clean` to remove all the built files, this command is usually used when something goes wrong during the compilation so that you can start fresh.


## Part 1: Malloc/free
As we write code, we often need to ensure the structure is available beyond the scope of a function. However, if we create a structure on the stack, the structure goes away when the stack rolls up. In these cases, we need to allocate memory on the heap. In C++, we can use the ‘new’ keyword. For example, `int[] something = new int[10];` which allocates a 10 integer array on the heap. There is, however, another method for allocating memory in C and C++ programs by using the ‘malloc()’ function. There are other related functions, such as calloc and realloc, that allocate memory. If you are interested in learning more about those functions, use man: man 3 malloc. The malloc function takes a single parameter, the memory size (in bytes) we want to allocate. For example, if we would like to allocate 8 bytes, we can call the command malloc(8);. The function returns the pointer to the first byte of the allocated memory block to be referenced later in our code. When we are done using that memory, we need to pass the memory reference to free() to manually de-allocate memory in use by our program that is no longer needed. If we do not do this our program will leak memory; that is, it will continue to be allocated, but our program no longer uses it and may not even have a reference to it. Please look at the following code, and then answer the related questions in the exercise about malloc:

```c++
#include <stdlib.h>  //Required for malloc, free

#include <iostream>  //Required for cout

using namespace std;

int main() {
  int* memory;  // Declares a new pointer

  // Assigns the pointer to allocated memory for 5 int objects
  memory = (int*)malloc(5 * sizeof(int));

	// If we get a null pointer, we ran out of memory
  if (memory == NULL) {
    return 1;
  }

  cout << "Memory Allocated At: " << memory << "\n";

  for (int i = 0; i < 5; i++) {
    memory[i] = i;  // Sets the values in the allocated array
  }

  for (int i = 0; i < 5; i++) {
    cout << memory[i] << " ";  // Prints out the allocated array
  }
  cout << "\n";

  free(memory);  // Frees the allocated memory

  cout << "Memory Has Been Freed.\n";

  return 0;
}
```
