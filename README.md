# COMPSCI 377 Exercise: Memory Allocation

## Purpose
This exercise is designed to cover various aspects of memory in C/C++: the `new` and `delete` keywords, pointers, and how to manipulate memory. Please ensure that all your answers to questions in these exercises are done on the Edlab environment – otherwise, they may be inconsistent results and will not receive points. Please read through this document and follow the instructions. After you do that, visit Gradescope and complete the questions associated with this exercise by the assigned due date.

## Setup
Once you have logged in to Edlab, you can clone this repo using
```
git clone https://github.com/umass-cs-377/377-lab-memory-allocation
```
Then you can use cd to open the directory you just cloned:
```
cd 377-lab-memory-allocation
```
This repository includes a Makefile that allows you to locally compile and run all the sample code listed in this tutorial. You can compile them by running make. Feel free to modify the source files yourself. After making changes, you need to run `make` again to build new binaries from your modified files. You can also use `make clean` to remove all the built files, this command is usually used when something goes wrong during the compilation so that you can start fresh.


## Part 1: Malloc/free
As we write code, we often need to ensure the structure is available beyond the scope of a function. However, if we create a structure on the stack, the structure goes away when the stack rolls up. In these cases, we need to allocate memory on the heap. In C++, we can use the ‘new’ keyword. For example, `int *something = new int[10];` which allocates a 10 integer array on the heap. There is, however, another method for allocating memory in C and C++ programs by using the ‘malloc()’ function. There are other related functions, such as calloc and realloc, that allocate memory. If you are interested in learning more about those functions, use man: man 3 malloc. The malloc function takes a single parameter, the memory size (in bytes) we want to allocate. For example, if we would like to allocate 8 bytes, we can call the command malloc(8);. The function returns the pointer to the first byte of the allocated memory block to be referenced later in our code. When we are done using that memory, we need to pass the memory reference to free() to manually de-allocate memory in use by our program that is no longer needed. If we do not do this our program will leak memory; that is, it will continue to be allocated, but our program no longer uses it and may not even have a reference to it. Please look at the following code, and then answer the related questions in the exercise about malloc:

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

## Part2 Pointers 

At the core, memory is just a sequence of bits with no inherent meaning. The programmer's job is to tell the compiler how to interpret these bits. That is where pointer types come in handy. If we have a block of memory, we can interpret that block as an array of `char`s by casting the pointer to the memory as `char *`. From now on, the compiler knows that the memory contains `char`'s, which is 1 byte (or 8 bits) long. We can now use pointer arithmetic to move the pointer 1 byte at a time. Take the example code below using pointers with arrays and how we can interpret the same memory as different types.

```c++
#include <stdlib.h>  //Required for malloc, free
#include <iostream>  //Required for cout
#include <cstring>

using namespace std;

class Wood {

public:
    int weight;
    int len;

    // constructer 
    Wood(double _weight = 4, double _len = 5) {
        weight = _weight;
        len = _len;
    }

    // destructer 
    ~Wood() {}
};

int main() {

  char *msg = new char[] {"Welcome to the lab about memory"};
  int *hidden = new int[] {1915184471, 1634213989, 1735289206, 1853187616,
                           1953068832, 1869619304, 1702129257, 555840370};
  Wood *pile = new Wood[8] {{1952871013, 1949656166}, {1936486508, 1869049199},
                            {1780507759, 846226031}, {862285153, 7037810}};

  /**
   * We can access elements in an array using [] notation
   */
  cout << "Message: ";
  for (int i = 0; i < 32; i++){
    cout << msg[i];
  }
  cout << '\n' << endl;

  /**
   * We can also access elements in an array by adding a vlaue to the pointer 
   * *(ptr + i)
   */
  cout << "Message: ";
  for (int i = 0; i < 32; i++){
    cout << *(msg + i);
  }
  cout << '\n' << endl;

  /**
   * The type of a pointer tells the compiler how many `bytes` it should move the
   * pointer by. For example, for `int *ptr` adding n (ptr +n) will move the 
   * pointer by `sizeof(int)*n` = 4*n. Casting `int *ptr` to `(char *) will only
   * the pointer by `sizeof(char)*n` = 1*n.
   */

  cout << "Let's decode the `hidden` message by casting the (int *) to (char *)" << endl;
  char *decode = (char *)hidden;
  cout << "Hidden Message: ";
  for (int i = 0; i < 32; i++){
    cout << decode[i];
  }
  cout << '\n' << endl;

  /**
   * We can also endcde char into int by casting (char *) to (int *)
   */ 
  cout << "Let's encode our msg into integers:" << endl;
  int *encode = (int *)msg;
  for (int i = 0; i < 8; i++){
    cout << encode[i] << " ";
  }
  cout << '\n' << endl;

  /**
   * In C++ we can use the `new` keyword to allocate memory on the heap.
   * If we allocate an array, the 8 bytes before the array contains the 
   * number of elements the array contains. Let's see what is stored
   * before `pile`
   */
  int64_t *j = ((int64_t *)pile) - 1;
  cout << "Before the `pile` array, C stores how many wood pieces we have: pile[" << *j << "]" << endl;

  /**
   * There are multiple methods for accessing elements within the array.
   */
  cout << "The 6'th piece of wood has a len of " << pile[5].len << endl;
  cout << "The 6'th piece of wood has a len of " << (pile+5)->len << endl;
  cout << "The 6'th piece of wood has a len of " << (*(pile+5)).len << endl;
  
  // Code goes here
  
  delete[] msg;
  delete[] hidden;
  delete[] pile;

}
```
