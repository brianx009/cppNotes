#include<iostream>

using std::cout;
using std::endl;

int add(int, int);    // function signature that passes in 2 parameters, names of parameters are not needed in signature

int add(int a, int b) {    // function definition, parameter names needed
  int sum = a + b;
  
  return sum;
}

int main(){

  //int result = add(1, 1);    // invoking a function
  std::cout << add(1,1) << std::endl;

  int arr[10];     
  int arrSize = std::size(arr);     // free function that is provided by the std c++ namespace

  std::string hello("Hello, World!");    // creating a object of type string -- string is a standard c++ class  
  int strLength = hello.length();    // using .length() member function that is specific to the string class. - not a free function.
                                     // member functions are also known as methods.
  
  return 0;

}
