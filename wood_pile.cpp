#include <stdlib.h>  //Required for malloc, free
#include <iostream>  //Required for cout
#include <cstring>

using namespace std;

class Wood {

public:
    int weight;
    int len;

    // constructer 
    Wood(int _weight = 4, int _len = 5) {
        weight = _weight;
        len = _len;
    }

    // destructer 
    ~Wood() {}
};

int main() {

  const char *s = "Welcome to the lab about memory";
  char *msg = new char[32];
  strcpy(msg, s);

  int *hidden = new int[32] {1915184471, 1634213989, 1735289206, 1853187616,
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
  

  delete[] msg;
  delete[] hidden;
  delete[] pile;

}
