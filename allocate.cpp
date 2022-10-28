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