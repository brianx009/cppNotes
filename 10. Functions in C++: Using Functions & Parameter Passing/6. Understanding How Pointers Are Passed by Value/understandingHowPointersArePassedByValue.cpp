#include<iostream>
#include<string>

using std::cout;
using std::endl;

// Example 1: This example + the example from 5. are to be used to show the behavior of passing by reference and passing by value when inside of functions. More specifically we are to note how memory addresses/ values behave when they are called in functions.


void updateRevenue(double* revenuePtr, double* anotherRevenuePtr);     //signature that takes in a pointer

int main(){

  double brianStoreRevenue = 100.00;     //creating a variable
  double brianStoreTwoRevenue = 200.00;     //creating a variable

  double* revenuePtr = &brianStoreRevenue;     //creating a pointer that points the memory address of our original varibale

  cout << "brianStoreRevenue before updateRevenue: " << brianStoreRevenue << endl;     //prints out the value of our orignal variable
  cout << "brianStoreRevenue address before updateRevenue: " << revenuePtr << endl;

  updateRevenue(revenuePtr, &brianStoreTwoRevenue);     //function call on our pointer

  cout << "brianStoreRevenue after updateRevenue: " << brianStoreRevenue << endl;     //prints out the value of our orignal variable because we never de-refferenced what brianStoreRevenue was/ changed it's value

  cout << "revenuePtr address after updateRevenue: " << revenuePtr << endl;    // prints out the same address as before because all we did was change what the pointer was pointing to, not its actual location in memory inside of the function, so when we jump back to our main function, it's as if nothing changed
    
  return 0;
}

void updateRevenue(double* revenuePtr, double* anotherRevenuePtr){
  cout << "Inside of updateRevenue" << endl;
  
  revenuePtr = anotherRevenuePtr;    //last example we had a *revenuePtr, but now we have revenuePtr, are the changes that we make here inside of this function going to change the contents of what is inside of our main funciton? -- the answer is no because we are still passing by value and not by reference. -- In summary, changes made to the values when using de-refferencing in a function will be preserved, while changes made to memory in a function will be forgottenlost.
  
}

